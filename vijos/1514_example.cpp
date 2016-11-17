include<cstdio> include<cmath> include<algorithm>
using namespace std;
int n,m,x,y,k;
int ans,f[200001][21];
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&f[i][0]);
	}
	for(int j=1; j<=20; j++) {
		for(int i=1; i<=n; i++) {
			if(i+(1<<j)-1<=n)
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	scanf("%d",&m);
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&x,&y);
		k=log(y-x+1)/log(2);
		ans=max(f[x][k],f[y-(1<<k)+1][k]);
		printf("%d\n",ans);
	}
	return 0;
}
