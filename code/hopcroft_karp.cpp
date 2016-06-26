// Assumes 0 is not a valid vertex
// Vertexes should be numbered according to partitions ([1..N] [N+1..M])
#define INF 0x3f3f3f3f
#define MAX ??

vector<int> G[MAX];
queue<int> Q;
int dist[MAX], match[MAX];
int N, M;

int bfs () {
    for (int u = 1; u <= N; u++) {
        if (!match[u]) {
            dist[u] = 0;
            Q.push(u);
        } else {
            dist[u] = INF;
        }
    }
    dist[0] = INF;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (dist[u] < dist[0]) {
            for (int i = 0; i < G[u].size(); i++) {
                int v = G[u][i];
                if (dist[match[v]] == INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return dist[0] != INF;
}

int dfs(int u) {
    if (!u) return 1;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (dist[match[v]] == dist[u] + 1) {
            if (dfs(match[v])) {
                match[v] = u;
                match[u] = v;
                return 1;
            }
        }
    }
    dist[u] = INF;
    return 0;
}

int hopcroft_karp() {
    memset(match, 0, sizeof(match));
    int size = 0;
    while (bfs()) {
        for (int u = 1; u <= N; u++) {
            if (match[u] == 0) {
                if (dfs(u)) size++;
            }
        }
    }
    return size;
}
