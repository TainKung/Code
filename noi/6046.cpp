#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int kMax=110;
int n, d[kMax];
int sum[kMax][kMax];
int a[kMax][kMax];

void read() {
    memset(d, 0, sizeof(d));
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", d+i);
}

void init() {
    memset(sum, 0, sizeof(sum));
    memset(a, 0, sizeof(a));
    for (int i=1; i<=n; i++) sum[i][i] = d[i];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        read();
        init();
        for (int k=1; k<n; k++) for (int i=1; i<=n-k; i++) {
            sum[i][i+k] = sum[i][i+k-1] + d[i+k];
            a[i][i+k] = a[i+1][i+k] + sum[i+1][i+k];
            for (int j=i+1; j<=i+k; j++) {
                int t = a[i+1][j] + d[i]*(j-i) + a[j+1][i+k] + (j-i+1)*sum[j+1][i+k];
                if (t < a[i][i+k]) a[i][i+k] = t;
            }
        }
        printf("%d\n", a[1][n]);
    }
    return 0;
}