// http://noi.openjudge.cn/ch0206/2985/
#include <cstdio>
#include <cstring>
using namespace std;

int a[20+1][1000+1], w[20];

int main(){
	int n, t, i, j;
	scanf("%d %d", &n, &t);
	for (i=1; i<=n; i++) scanf("%d", w+i);
	memset(a, 0, sizeof(a));
	for (i=0; i<=n; i++) a[i][0]=1;
	for (i=1; i<=n; i++) for (j=1; j<=t; j++){
		a[i][j]=a[i-1][j];
		if (j >= w[i]) a[i][j] += a[i-1][j-w[i]];
	}
	printf("%d\n", a[n][t]);
	return 0;
}