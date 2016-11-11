#include <cstdio>
#include <cstring>

const int kMax=50;
int num[kMax][kMax], a[kMax][10];
char c[kMax];

inline int max(int a, int b) { return (a>b)? a:b; }

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", c);

    memset(num, 0, sizeof(num));
    for (int i=0; i<n; i++) for (int j=i; j<n; j++)
        num[i][j] = num[i][j-1]*10 + (c[j] - '0');

    memset(a, 0, sizeof(a));
    for (int i=0; i<n; i++) a[i][0] = num[0][i];
    for (int i=0; i<n; i++) for (int j=1; j<=k; j++) {
        for (int p=j-1; p<i; p++)
            a[i][j] = max(a[i][j], a[p][j-1] * num[p+1][i]);
    }
    
    printf("%d\n", a[n-1][k]);
    return 0;
}
