#include <cstdio>
#include <cstring>
#include <cstdlib>

#define DEBUG 1
#ifdef DEBUG
#define debug(a) a
#else
#define debug(a)
#endif

#define INIT(arr, value) memset(arr, value, sizeof(arr))

const int kMax=128;
int num[150][150];
int d, n;

inline int max(int a, int b) { return (a>b)? a:b; }

int cal(int x, int y) {
    int result = 0;
    for (int i=max(x-d, 0); i<=x+d && i<=kMax; i++)
        for (int j=max(y-d, 0); j<=y+d && j<=kMax; j++)
            result += num[i][j];
    return result;
}

int main() {
    scanf("%d%d", &d, &n);
    INIT(num, 0);
    for (int i=0, x, y, k; i<n; i++) {
        scanf("%d%d%d", &x, &y, &k);
        num[x][y] += k;
    }
    int ans = 0, k = 1;
    for (int x=0; x<=kMax; x++)
        for (int y=0; y<=kMax; y++) {
            int temp = cal(x, y);
            if (temp > ans) {
                ans = temp;
                k = 1;
            } else if (temp == ans) k++;
        }
    printf("%d %d\n", k, ans);
    return 0;
}
