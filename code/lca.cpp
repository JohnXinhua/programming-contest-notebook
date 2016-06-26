#define MAX ??
#define LOGMAX ??

vector<int> G[MAX];
int L[MAX], P[MAX][LOGMAX], T[MAX];
int N;

void process_anc() {
    int i, j;

    //initialize every element in P with -1
    for (i = 0; i< N; i++)
        for(j = 0; 1<<j < N; j++)
            P[i][j] = -1;

    //the first ancestor of every node i is T[i]
    for (i = 0; i < N; i++)
        P[i][0] = T[i];

    //bottom up dynamic programing
    for (j =1; 1<<j < N; j++)
        for (i = 0; i < N; i++)
            if(P[i][j -1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
}

int lca(int p, int q) {
    int tmp, log, i;

    //if p is situated on a higher level than q then we swap them
    if(L[p] < L[q])
        tmp = p, p = q, q = tmp;

    //compute the value of [log(L[p)]
    for (log = 1; 1 << log <= L[p]; log++);
    log--;

    //find the ancestor of node p situated on the same level
    //with q using the values in P
    for(i = log; i >= 0; i--)
        if(L[p] - (1<<i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    //we compute LCA(p, q) using the values in P
    for (i = log; i >= 0; i--)
        if(P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}

/*
init values for 0
L[0] = 0;
T[0] = -1;

foreach node set values accordingly
T[i] = father of node i;
L[i] = level of node i;

call process_anc() to compute lca tree
*/

