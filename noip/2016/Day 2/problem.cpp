#include <cstdio>
#include <cstring>
#include <cstdlib>

#define DEBUG
#ifdef DEBUG
#define debug(a) a
#else
#define debug(a)
#endif

#define INIT(arr, value) memset(arr, value, sizeof(arr))

const int kMax=2001;
int c[kMax][kMax], sum[kMax][kMax];
bool b[kMax][kMax];

inline int min(int a, int b) { return (a<b)? a:b; }

int main() {
    int t, k;
    scanf("%d%d", &t, &k);
    INIT(c, 0); INIT(b, 0);
    for (int i=0; i<kMax; i++) c[i][0] = 1;
    for (int i=1; i<kMax; i++) for (int j=1; j<=i; j++) {
        c[i][j] = (c[i-1][j-1] + c[i-1][j]) % k;
        if (c[i][j] == 0) b[i][j] = 1;
    }
    INIT(sum, 0);
    for (int i=1; i<kMax; i++) for (int j=1; j<kMax; j++)
        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + b[i][j];
    int n, m;
    while (t--) {
        scanf("%d%d", &n, &m);
        printf("%d\n", sum[n][min(n, m)]);
    }
    return 0;
}
