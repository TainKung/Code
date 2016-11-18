#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>

#define DEBUG 1
#ifdef DEBUG
#define debug(a) a
#else
#define debug(a)
#endif

#define INIT(arr, value) memset(arr, value, sizeof(arr))

const int kMax=101;
int map[kMax][kMax], dis[kMax][kMax];
int ans, n, m;

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        ans = INT_MAX;
        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) dis[i][j] = map[i][j] = 1000000;
        for (int i=0, u, v, t; i<m; i++) {
            scanf("%d%d%d", &u, &v, &t);
            dis[u][v] = dis[v][u] = map[u][v] = map[v][u] = t;
        }
        for (int k=1; k<=n; k++) {
            for (int i=1; i<k; i++) for (int j=1; j<i; j++) {
                int temp = map[i][k] + map[j][k] + dis[i][j];
                if (temp < ans) ans = temp;
            }
            for (int i=1; i<=n; i++) for (int j=1; i!=k && j<i; j++) {
                int temp = dis[i][k] + dis[j][k];
                if (temp < dis[i][j]) dis[i][j] = dis[j][i] = temp;
            }
        }
        if (ans < 1000000 && ans > 0) printf("%d\n", ans);
        else printf("No solution.\n");
    }
    return 0;
}
