// http://noi.openjudge.cn/ch0206/1944/
#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	memset(a, 0, sizeof(a));
	a[0]=1; a[1]=2;
	for (int i=2; i<n; i++) a[i] = a[i-1] + a[i-2];
	printf("%d\n", a[n-1]);
	return 0;
}