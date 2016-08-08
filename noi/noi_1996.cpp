// http://noi.openjudge.cn/ch0206/1996/
#include <stdio.h>
#include <string.h>

inline int max(int a, int b){ return (a>b)? a:b;}

int main(){
	int n, i, j;
	scanf("%d", &n);
	int h[n+2], a[n+2], b[n+2];
	for (i=1; i<=n; i++) scanf("%d", h+i);
	h[0] = h[n+1] = 0;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (i=1; i<=n; i++) for (j=0; j<i; j++)
		if (h[i] > h[j] && a[i] <= a[j])
			a[i] = a[j]+1;
	for (i=n; i>=1; i--) for (j=n+1; j>i; j--)
		if (h[i] > h[j] && b[i] <= b[j])
			b[i] = b[j]+1;
	int ans=0;
	for (i=1; i<=n; i++) ans = max(ans, a[i]+b[i]-1);
	printf("%d\n", ans);
	return 0;
}