// http://noi.openjudge.cn/ch0206/3532/
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=1000;
int a[MAXN+1], ans[MAXN+1];

inline int max(int a, int b){ return (a>b)? a:b;}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", a+i);
	ans[0]=0; a[0]=-1;
	for (int i=1; i<=n; i++) for (int j=0; j<i; j++)
		if (a[j]<a[i]) ans[i] = max(ans[i], ans[j] + a[i]);
	int m=0;
	for (int i=1; i<=n; i++) m = max(m, ans[i]);
	printf("%d\n", m);
	return 0;
}