// http://noi.openjudge.cn/ch0308/2405/
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=102;
bool a[maxn][maxn];
// int n, m, k;
int dx[]={0, 1, 0, -1}, dy[]={1, 0, -1, 0};

int search(int x, int y){
	int ans=1;
	a[x][y] = 0;
	for (int i=0; i<4; i++) if (a[x+dx[i]][y+dy[i]])
		ans += search(x+dx[i], y+dy[i]);
	return ans;
}

inline int max(int a, int b){return (a>b)?a:b;}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	memset(a, 0, sizeof(a));
	int x, y, ans=0;
	for (int i=0; i<k; i++){
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
		if (a[i][j]) ans = max(ans, search(i, j));
	printf("%d\n", ans);
	return 0;
}