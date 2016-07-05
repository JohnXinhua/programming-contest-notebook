#define MAXN ??
#define INFINITY 0x3f3f3f3f
#define MIN(a, b) (((a)<(b))?(a):(b))

vector<int> G[MAXN];
int C[MAXN][MAXN], F[MAXN][MAXN];

int edmonds_karp (int s, int t) {
    int mflow = 0, cur, df, to, prev;
    queue<int> Q;
    int P[MAXN]; // predecessor
    while (true) {
        // bfs augmenting path starting from source
        memset(P, -1, sizeof(P));
        Q.push(s);
        while (!Q.empty()) {
            cur = Q.front();
            Q.pop();
            for (int i = 0; i < G[cur].size(); i++) {
                to = G[cur][i];
                if (P[to] == -1 && to != s && C[cur][to] > F[cur][to]) {
                    P[to] = cur;
                    Q.push(to);
                }
            }
        }
        // no more augmenting paths leading to target
        if (P[t] == -1) break;
        df = INFINITY;
        cur = t;
        // trace min cap of path
        while (P[cur] != -1) {
            prev = P[cur];
            df = MIN(df, C[prev][cur] - F[prev][cur]);
            cur = prev;
        }
        cur = t;
        // update path's vertices flow
        while (P[cur] != -1) {
            prev = P[cur];
            F[prev][cur] += df;
            F[cur][prev] -= df;
            cur = prev;
        }
        // increase max flow by path flow
        mflow += df;
    }
    return mflow;
}
