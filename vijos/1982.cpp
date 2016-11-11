#include <cstdio>
#include <cstring>

const int kM=1000000007;
int a[1010][210][210];
char sa[1010], sb[210];

int main() {
    int n, m, k;
    scanf("%d%d%d%s%s", &n, &m, &k, sa, sb);

    memset(a, 0, sizeof(a));
    for (int i=0; i<=n; i++) a[i][0][0] = 1;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) for (int t=1; t<=k; t++) {
        a[i][j][t] = a[i-1][j][t];
        for (int p=i, q=j; p != 0 && q != 0 && sa[p-1] == sb[q-1]; p--, q--) {
            a[i][j][t] += a[p-1][q-1][t-1];
            a[i][j][t] %= kM;
        }
    } 

    printf("%d\n", a[n][m][k]);
    return 0;
}
