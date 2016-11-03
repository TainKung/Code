#include <cstdio>
#include <cstring>
using namespace std;

const int kMax=30;
bool a[kMax][kMax];
char sa[kMax], sb[kMax];
int la, lb;

int main() {
    scanf("%s", sa);
    scanf("%s", sb);
    la = strlen(sa);
    lb = strlen(sb);

    memset(a, 0, sizeof(a));
    a[0][0] = 1;
    for (int i=1; i<=la; i++) for (int j=1; j<=lb; j++) {
        switch (sa[i-1]) {
            case '?':
                a[i][j] = a[i-1][j-1];
                break;
            case '*':
                for (int k=j; k>=0 && !a[i][j]; k--) 
                    a[i][j] |= a[i-1][k];
                break;
            default:
                if (sa[i-1] == sb[j-1]) a[i][j] = a[i-1][j-1];
        }
    }

    printf(a[la][lb]? "matched\n" : "not matched\n");
    return 0;
}