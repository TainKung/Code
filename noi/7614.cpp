#include <cstdio>
#include <cstring>

const int kMax=110;
int a[kMax][kMax];
int w[kMax][kMax];

inline int min(int a, int b) { return (a<b)? a:b; }

int main () {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++)
        scanf("%d", &w[i][j]);

    memset(a, 0, sizeof(a));
    a[1][1] = w[1][1];
    for (int i=2; i<=n; i++){
        a[i][1] = a[i-1][1] + w[i][1];
        a[1][i] = a[1][i-1] + w[1][i];
    }
    for (int i=2; i<=n; i++) for (int j=2; j<=n; j++)
        a[i][j] = min(a[i-1][j], a[i][j-1]) + w[i][j];

    printf("%d\n", a[n][n]);
    return 0;
}
