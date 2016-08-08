// http://noi.openjudge.cn/ch0206/4978/
#include <cstdio>
using namespace std;

inline int max(int a, int b){ return (a>b)? a:b;}

int a[101][1001][501], ball[101], hp[101];

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i=1; i<=k; i++) scanf("%d %d", ball+i, hp+i);
	for (int i=1; i<=k; i++) for (int j=1; j<=n; j++) for (int t=1; t<=m; t++){
		a[i][j][t] = a[i-1][j][t];
		if (j>=ball[i] && t>=hp[i])
			a[i][j][t] = max(a[i][j][t], a[i-1][j-ball[i]][t-hp[i]]+1); 
	}
	int maxn=0, maxhp=0;
	for (int i=1; i<=m; i++) if (a[k][n][i] > maxn){
		maxn = a[k][n][i]; maxhp=i;
	}
	printf("%d %d\n", maxn, m-maxhp);
	return 0;
}