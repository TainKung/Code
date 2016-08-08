#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100;
int a[maxn][maxn], n;
bool b[maxn];

enum DIR{ROW, COLUMN};

inline int min(int a, int b){return (a<b)? a:b;}

int findMin(int p, DIR d){
	int ans=1e9;
	for (int i=0; i<n; i++) if (b[i])
		ans = min(ans, (d == ROW)? a[p][i]:a[i][p]);
	return ans;
}

void decMin(int p, DIR d){
	int x = findMin(p, d);
	if (x == 0) return;
	for (int i=0; i<n; i++) if (b[i])
		if (d == ROW) a[p][i] -= x;
		else a[i][p] -= x; 
}

int main(){
	scanf("%d", &n);
	memset(b, 1, sizeof(b));
	for (int i=0; i<n; i++) for (int j=0; j<n; j++)
		scanf("%d", &a[i][j]);
	printf("%d\n", a[1][1]);
	for (int k=1; k<n; k++){
		for (int i=0; i<n; i++) if (b[i]){
			decMin(i, ROW); decMin(i, COLUMN);
		}
		printf("%d\n", a[k][k]);
		b[k] = 0;
	}
	return 0;
}