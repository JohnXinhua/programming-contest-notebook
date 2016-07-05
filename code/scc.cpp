// I is index, LL is low link and OS is on stack
// idx and count start as 0, I and LL as -1 and OS as false
#define min(a, b) ((a) < (b))?(a):(b)
#define MAXN ??

int N, M, idx;
int I[MAXN], LL[MAXN];
bool OS[MAXN];
stack<int> S;
vector<int> G[MAXN];

void strong_connect (int v) {
    int w;
    // set the depth index for v to the smallest unused index
    I[v] = idx;
    LL[v] = idx;
    idx++;
    S.push(v);
    OS[v] = true;

    // consider successors of v
    for (int i = 0; i < G[v].size(); i++) {
        w = G[v][i];
        if (I[w] == -1) {
            // successor w has not yet been visited; recurse on it
            strong_connect(w);
            LL[v] = min(LL[v], LL[w]);
        } else if (OS[w]) {
            // successor w is in stack S and hence in the current SCC
            LL[v] = min(LL[v], I[w]);
        }
    }

    // if v is a root node, pop the stack and generate an SCC
    if (LL[v] == I[v]) {
        //start a new strongly connected component
        do {
            w = S.top();
            S.pop();
            OS[w] = false;
            // add w to current strongly connected component
        } while (w != v);
        // output the current strongly connected component
    }
}
