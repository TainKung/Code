// http://noi.openjudge.cn/ch0206/1768/
#include <stdio.h>
#include <string.h>

inline int max(int a, int b){return (a>b)?a:b;}

int main(){
	int n, i, j, p, q;
	scanf("%d", &n);
	int a[n+1][n+1], b[n+1][n+1], sum[n+1][n+1];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(sum,0,sizeof(sum));
	for (i=1; i<=n; i++) for (j=1; j<=n; j++){
		scanf("%d", &a[i][j]);
		b[i][j]=a[i][j];
	}
	for (i=1; i<=n; i++) for (j=1; j<=n; j++){
		b[i][j]+=b[i][j-1];
		sum[i][j]=b[i][j];
	}
	for (i=1; i<=n; i++) for (j=1; j<=n; j++){
		sum[i][j]+=sum[i-1][j];
	}
	int ans=0;
	for (i=1; i<=n; i++) for (j=1; j<=n; j++) for (p=0; p<=i; p++) for (q=0; q<=j; q++)
			ans=max(sum[i][j]-sum[p][j]-sum[i][q]+sum[p][q],ans);
	printf("%d\n", ans);
	return 0;
}
