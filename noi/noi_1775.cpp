// http://noi.openjudge.cn/ch0206/1775/
#include <stdio.h>
#include <string.h>

inline int max(int a, int b){ return (a>b)? a:b;}

int main(){
	int T, M, i, j;
	scanf("%d %d", &T, &M);
	int tm[M+1], val[M+1], ans[T+1][M+1];
	for (i=1; i<=M; i++) scanf("%d %d", tm+i, val+i);
	memset(ans, 0, sizeof(ans));
	for (i=1; i<=T; i++) for (j=1; j<=M; j++)
		ans[i][j] = max((i>=tm[j])?ans[i-tm[j]][j-1]+val[j]:0, ans[i][j-1]);
	printf("%d\n", ans[T][M]);
	return 0;
}