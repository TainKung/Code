// http://noi.openjudge.cn/ch0206/7627/ Vision 2.0
// This vision uses DP instead of Recursive
#include <stdio.h>
#include <string.h>

inline int max(int a, int b){ return (a>b)? a:b; }
inline int min(int a, int b){ return (a<b)? a:b; } 

int main(){
	int a[100+1][10+1];
	memset(a,127,sizeof(a));
	int i, j, p;
	for (i=1; i<=100; i++){
		a[i][1]=i; a[i][0]=0;
	}
	for (i=1; i<=10; i++){
		a[1][i]=1; a[0][i]=0;
	}
	for (i=2; i<=100; i++)
		for (j=2; j<=10; j++)
			for (p=1; p<=i; p++)
				a[i][j]=min(a[i][j], max(a[p-1][j-1], a[i-p][j]) + 1);
	while (scanf("%d %d", &i, &j) != EOF) printf("%d\n", a[i][j]);
	return 0;
}