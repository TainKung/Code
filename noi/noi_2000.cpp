// http://noi.openjudge.cn/ch0206/2000/
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN=500;
int prea[MAXN+1][MAXN+1], preb[MAXN+1][MAXN+1], ans[MAXN+1][MAXN+1];
int a[MAXN], b[MAXN], list[MAXN];

namespace my{
	int max(int &ans, int a1, int a2, int a3){
		if (a1 >= a2 && a1 >= a3){
			ans=a1; return 1;
		}
		else if (a2 >= a3){
			ans=a2; return 2;
		}
		else{
			ans=a3; return 3;
		}
	}
}

int main(){
	int lena, lenb, i, j;
	scanf("%d", &lena);
	for (i=0; i<lena; i++) scanf("%d", a+i);
	scanf("%d", &lenb);
	for (i=0; i<lenb; i++) scanf("%d", b+i);
	for (i=1; i<=lena; i++) for (j=1; j<=lenb; j++)
		switch (my::max(ans[i][j], ans[i-1][j], ans[i][j-1], ans[i-1][j-1] + (a[i-1] == b[j-1]))){
			case 1:
				prea[i][j]=prea[i-1][j];
				preb[i][j]=preb[i-1][j];
				break;
			case 2:
				prea[i][j]=prea[i][j-1];
				preb[i][j]=preb[i][j-1];
				break;
			case 3:
				if (a[i-1] == b[j-1]){
					prea[i][j]=i;
					preb[i][j]=j;
				}
				else {
					prea[i][j]=prea[i-1][j-1];
					preb[i][j]=preb[i-1][j-1];
				}
				break;
		}
	int x=prea[lena][lenb], y=preb[lena][lenb], p=0, temp;
	while (x && y){
		list[p++] = a[x-1];
		temp = x;
		x = prea[x-1][y-1];
		y = preb[temp-1][y-1];
	}
	printf("%d\n", ans[lena][lenb]);
	for (p-=1; p!=-1; p--) printf("%d ", list[p]);
	printf("\n");
	return 0;
}