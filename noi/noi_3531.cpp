// http://noi.openjudge.cn/ch0206/3531/
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=100;
int w[10000+1];
bool a[10000+1][MAXN];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	memset(a, 0, sizeof(a));
	for (int i=1; i<=n; i++) scanf("%d", w+i);
	a[1][(k-w[1]%k)%k]=1; a[1][w[1]%k]=1;
	for (int i=1; i<n; i++) for (int j=0; j<k; j++)
		if (a[i][j]){
			a[i+1][(j-w[i+1]%k+k)%k] = a[i][j];
			a[i+1][(j+w[i+1])%k] = a[i][j];
		}
	printf((a[n][0])? "YES\n":"NO\n");
	return 0;
}