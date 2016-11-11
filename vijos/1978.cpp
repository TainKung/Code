#include <cstdio>
#include <cstring>

const int kMax=40;
int a[kMax][kMax];

int main() {
    int n;
    scanf("%d", &n);
    
    memset(a, 0, sizeof(a));
    int x=1, y=(n+1)/2;
    a[x][y] = 1;
    for (int k=2; k<=n*n; k++) {
        if (x == 1 && y == n) x++;
        else if (x == 1) {
            y++; x = n;
        } else if (y == n) {
            x--; y = 1;
        } else if (a[x-1][y+1] == 0) {
            x--; y++;
        } else x++;
        a[x][y] = k;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
