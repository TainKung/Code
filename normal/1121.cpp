// vijos 1121
#include <stdio.h>
#include <string.h>

const int dx[9]={-2,-2,-1,-1, 0, 1, 1, 2, 2};
const int dy[9]={ 1,-1, 2,-2, 0, 2,-2, 1,-1};

int main(){
	int n,m,x,y;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	n++; m++; x++; y++;
	int i, j, map[n+2][m+2];
	memset(map,0,sizeof(map));
	for (i=0; i<9; i++)
		if (x+dx[i]>=0 && x+dx[i] <=n && y+dy[i] >=0 && y+dy[i] <=m)
			map[x+dx[i]][y+dy[i]]=-1;
	map[1][1]=1;
	for (i=1; i<=n; i++) for (j=1; j<=m; j++) if (map[i][j]+1){
		if (map[i-1][j]>0) map[i][j] += map[i-1][j];
		if (map[i][j-1]>0) map[i][j] += map[i][j-1];
	}
	printf("%d\n",map[n][m]);
	return 0;
}