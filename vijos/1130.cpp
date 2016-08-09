// vijos 1130
#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int ans[n+1];
	ans[1]=1;
	for (int i=2;i<=n;i++)
		if (i & 1) ans[i]=ans[i-1];
		else ans[i]=ans[i-1]+ans[i/2];
	printf("%d\n",ans[n]);
	return 0;
}