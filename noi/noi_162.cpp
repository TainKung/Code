// http://noi.openjudge.cn/ch0206/162/
#include <stdio.h>
#include <string.h>

const int MAXV=300, MAXP=30;
int x[MAXV], ans[MAXV][MAXP], s[MAXV];

inline int abs(int x){return (x>0)?x:-x;}

int cal(int l, int r){
	if (l==r) return 0;
	int mid=(l+r)/2;
	return s[r]+s[l]-2*s[mid]-x[l]+(2*mid-l-r+1)*x[mid];
}

inline int min(int a, int b){return (a<b)? a:b;}

int main(){
	int vill, pos;
	scanf("%d %d", &vill, &pos);
	int i,j,p;
	for (i=0; i<vill; i++){
		scanf("%d", x+i); s[i]=x[i];
	}
	for (i=1; i<vill; i++) s[i]+=s[i-1];
	memset(ans,127,sizeof(ans));
	for (i=0; i<vill; i++) ans[i][0]=cal(0,i);
	for (i=0; i<vill; i++)
		for (j=1; j<min(pos,i); j++)
			for (p=j-1; p<i; p++)
				ans[i][j] = min(ans[i][j], ans[p][j-1] + cal(p+1, i));
	printf("%d\n", ans[vill-1][pos-1]);
	return 0;
}