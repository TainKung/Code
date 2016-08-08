// http://noi.openjudge.cn/ch0206/4977/
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=100;
int h[MAXN+2], ans[MAXN+2];

inline int max(int a, int b){ return (a>b)? a:b;}

int main(){
	int k;
	scanf("%d", &k);
	while (k--){
		int n;
		scanf("%d", &n);
		for (int i=1; i<=n; i++) scanf("%d", h+i);
		h[0] = h[n+1] = 0;
		int m1=0, m2=0;
		memset(ans, 0, sizeof(ans));
		for (int i=1; i<=n; i++){
			for (int j=0; j<i; j++) if (h[j] < h[i])
				ans[i] = max(ans[i], ans[j] + 1);
			m1 = max(m1, ans[i]);
		}
		memset(ans, 0, sizeof(ans));
		for (int i=n; i>=1; i--){
			for (int j=n+1; j>i; j--) if (h[j] < h[i])
				ans[i] = max(ans[i], ans[j] + 1);
			m2 = max(m2, ans[i]);
		}
		printf("%d\n", max(m1, m2));
	}
	return 0;
}