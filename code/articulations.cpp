// A[v] has 1 if v is a cut vertex
#define MAXN ??
int N, D[MAXN], P[MAXN], L[MAXN], A[MAXN];
vector<int> G[MAXN];

int art(int u, int d) {
    int low = D[u] = d, cc = 0, is_art = 0;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!D[v]) {
            P[v] = u;
            art(v, d + 1);
            cc++;
            if (L[v] >= D[u]) is_art = 1;
            L[u] = MIN(L[u], L[v]);
        } else if (v != P[u]) {
            L[u] = MIN(L[u], D[v]);
        }
    }
    if ((P[u] != 0 && is_art) || (P[u] == 0 && cc > 1)) A[u] = 1;
}

void get_art() {
    memset(A, 0, sizeof(A));
    memset(D, 0, sizeof(D));
    memset(L, 0, sizeof(L));
    memset(P, 0, sizeof(P));
    dfs(1, 0);
}
