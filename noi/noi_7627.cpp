// http://noi.openjudge.cn/ch0206/7627/
#include <stdio.h>
#include <string.h>

int main(){
	int n=1000, m=10, i, j;
	int a[m+1][n+1];
	for (i=1; i<=n; i++) a[1][i]=i;
	for (i=1; i<=m; i++) a[i][1]=1;
	for (i=2; i<=m; i++)
		for (j=2; j<=n; j++){
			a[i][j]=a[i][j-1]+a[i-1][j-1]+1;
		}
	while (scanf("%d %d", &n, &m)!=EOF){
		for (i=1; i<=n; i++) if (a[m][i]>=n) break;
		printf("%d\n", i);
	}
	return 0;
}