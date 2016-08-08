// http://noi.openjudge.cn/ch0206/2989/
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN=100;
int a[MAXN+1][MAXN], w[MAXN+1];

inline int max(int a, int b){ return (a>b)? a:b; }

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	memset(a, 0xff, sizeof(a));
	for (int i=1; i<=n; i++) scanf("%d", w+i);
	a[1][0]=0; a[1][w[1]%k]=w[1];
	for (int i=1; i<n; i++) for (int j=0; j<k; j++)
		if (a[i][j]>=0){
			a[i+1][j] = max(a[i+1][j], a[i][j]);
			a[i+1][(j+w[i+1])%k] = max(a[i+1][(j+w[i+1])%k], a[i][j] + w[i+1]);
		}
	printf("%d\n", (a[n][0] != -1)? a[n][0]:0);
	return 0;
}