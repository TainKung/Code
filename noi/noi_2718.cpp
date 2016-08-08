// http://noi.openjudge.cn/ch0206/2718/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN=20;
int a[MAXN][MAXN];

int main(){
	memset(a, 0, sizeof(a));
	int i, j, m, n;
	scanf("%d %d", &m, &n);
	for (i=0; i<m; i++) a[i][0]=1;
	for (i=0; i<n; i++) a[0][i]=1;
	for (i=1; i<=m; i++) for (j=1; j<=n; j++)
		a[i][j] = a[i-1][j] + a[i][j-1];
	cout << a[m-1][n-1] << endl;
	return 0;
}