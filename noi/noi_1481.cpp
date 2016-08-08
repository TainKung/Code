// http://noi.openjudge.cn/ch0206/1481/
#include <stdio.h>
#include <string.h>

const int MAXN=50000;
int n, a[MAXN+1], ca[MAXN+2], cb[MAXN+2];

inline int max(int a, int b){ return (a>b)? a:b;}

void cal(){
	int i;
	ca[0]=ca[n+1]=cb[0]=cb[n+1]=0;
	for (i=1; i<=n; i++) ca[i]=cb[i]=a[i];
	for (i=1; i<n; i++) if (ca[i-1]>0) ca[i]+=ca[i-1];
	for (i=n; i>1; i--) if (cb[i+1]>0) cb[i]+=cb[i+1];
	// for (i=0; i<=n+1; i++) printf("%d ", ca[i]);
	// printf("\n");
	// for (i=0; i<=n+1; i++) printf("%d ", cb[i]);
	// printf("\n");
	for (i=2; i<n; i++) ca[i]=max(ca[i], ca[i-1]);
	for (i=n-1; i>1; i--) cb[i]=max(cb[i], cb[i+1]);
	// for (i=0; i<=n+1; i++) printf("%d ", ca[i]);
	// printf("\n");
	// for (i=0; i<=n+1; i++) printf("%d ", cb[i]);
	// printf("\n");
}

int main(){
	int T, i, ans;
	scanf("%d", &T);
	while (T){
		scanf("%d", &n);
		for (i=1; i<=n; i++) scanf("%d", a+i);
		cal(); ans=ca[1]+cb[2];
		for (i=2; i<n; i++) ans=max(ans, ca[i] + cb[i+1]);
		printf("%d\n", ans);
		T--;
	}
	return 0;
}