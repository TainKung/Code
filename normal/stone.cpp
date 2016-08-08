#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int A[60000],n,L,m,f[60000];
int check(int k){
	int pre=0,ans=0;
	for (int i=1;i<=n+1;i++){
		while (A[i]-A[pre+1]>=k){
			pre++; ans=min(ans,f[pre]-pre);
		}
		if (A[i]-A[pre]<k) f[i]=1e9; else f[i]=ans+i-1;
	}
	return f[n+1]<=m;
}
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d%d%d",&L,&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	A[n+1]=L; 
	int l=1,r=L+1,ans=0;
	while (l<r){
		int mid=l+r>>1;
		if (check(mid)){
			ans=mid; l=mid+1;
		} else r=mid;
	}
	printf("%d\n",ans);
	return 0;
}
