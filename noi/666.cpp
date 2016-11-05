#include <cstdio>
#include <cstring>

const int kMax=20;
int a[kMax][kMax];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int m, n;
        scanf("%d%d", &m, &n);

        memset(a, 0, sizeof(a));
        a[0][0] = 1;
        for (int i=0; i<=m; i++) for (int j=1; j<=n; j++) {
            a[i][j] = a[i][j-1];
            if (i >= j) a[i][j] += a[i-j][j];
        }

        printf("%d\n", a[m][n]);
    }
    return 0;
}
