#define MAXN ??
#define INF 0x3f3f3f3f
int D[MAXN];
bool V[MAXN];
int N;
vector< pair<int, int> > G[MAXN];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q;

void dijkstra(int s) {
    memset(D, 0x3f, sizeof(D));
    memset(V, false, sizeof(V));
    Q.push(make_pair(0, s));
    while (!Q.empty()) {
        v = Q.top().second;
        dist = Q.top().first;
        if (!V[v]) {
            V[v] = true;
            D[v] = dist;
            // if you are searching for dist(pair<s, d>) and finds d you can return it here
            for (int i = 0; i < G[v].size(); i++) {
                Q.push(make_pair(dist + G[v][i].first, i));
            }
        }
        Q.pop();
    }
}
