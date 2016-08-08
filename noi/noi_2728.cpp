// http://noi.openjudge.cn/ch0206/2728/
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=100;
int a[MAXN+1][MAXN+1], ans[MAXN+1][MAXN+1];

inline int max(int a, int b){ return (a>b)? a:b; }

int main(){
	int t; scanf("%d", &t);
	while (t--){
		int m, n, i, j;
		scanf("%d %d", &m, &n);
		memset(ans, 0, sizeof(ans));
		for (i=1; i<=m; i++) for (j=1; j<=n; j++)
			scanf("%d", &a[i][j]);
		for (i=1; i<=m; i++) for (j=1; j<=n; j++)
			ans[i][j] = max(ans[i-1][j], ans[i][j-1]) + a[i][j];
		printf("%d\n", ans[m][n]);
	}
	return 0;
}