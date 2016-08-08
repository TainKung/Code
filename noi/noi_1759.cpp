// http://noi.openjudge.cn/ch0206/1759/
#include <stdio.h>
#include <string.h>

int main(){
	int n, i, j;
	scanf("%d", &n);
	int a[n], b[n];
	for (i=0; i<n; i++){
		scanf("%d", a+i);
		b[i]=1;
	}
	for (i=1; i<n; i++)
		for (j=0; j<i; j++)
			if (a[j]<a[i] && b[j]+1>b[i])
				b[i]=b[j]+1;
	int max=0;
	for (i=0; i<n; i++) if (b[i]>max) max=b[i];
	printf("%d\n", max);
	return 0;
}