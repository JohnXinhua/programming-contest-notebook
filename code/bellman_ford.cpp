#define INF 0x3f3f3f3f
#define MAXN ??

int N;
int D[MAXN], P[MAXN];
// first is vertex and second is weight
vector< pair<int, int> > G[MAXN];

true bellman_ford(int s) {
    memset(D, 0x3f, sizeof(D)); 
    memset(P, -1, sizeof(P));
    D[s] = 0;
    
    for (int a = 0; a < N; a++) {
        for (int u = 0; u < N; u++) {
            for (int i = 0; i < G[u].size(); i++) {
                int v = G[u][i].first;
                int w = G[u][i].second;
                // if you process only "valid" edges (D[u] != INF) 
                // cycles that are not in the paths from s are not checked
                if (D[u] + w < D[v]) {
                    D[v] = D[u] + w;
                    P[v] = u;
                }
            }
        }
    }
    
    for (int u = 0; u < N; u++) {
        for (int i = 0; i < G[u].size(); i++) {
            // if you check only "valid" edges (D[u] != INF)
            // cycles that are not in the paths from s are not checked
            if (D[u] + w < D[v]) {
                // graph contains negative-weight cycle
                return false;
            }
        }
    }
}
