// D should be INF when there is no arc or when it was not computed by DP
// D[i][j][0] should contain the weight of the arc (i, j) before running the DP
// This DP calculates every shortest k-path distance between all pairs of vertices
// So D[i][j][k] is the distance of the shortest k-path from i to j
// And D[i][j][N] is the distance of the shortest path from i to j
#define MAXN ??
#define INF 0x3f3f3f3f
#define MIN(a, b) (((a)<(b))?(a):(b))
int D[MAXN][MAXN][MAXN];
int N;

void floyd_warshall() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                D[i][j][k] = MIN(D[i][j][k-1], D[i][k][k-1] + D[k][j][k-1]);
            }
        }
    }
}