// http://noi.openjudge.cn/ch0206/4978/ Vision 2
#include <cstdio>
using namespace std;

inline int min(int a, int b){ return (a<b)? a:b;}

int a[101][1001][2], ball[101], hp[101];

int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int m1=0, m2=0;
	for (int i=1; i<=K; i++) scanf("%d %d", ball+i, hp+i);
	for (int i=1; i<=K; i++) for (int j=1; j<=N; j++){
		a[i][j][0] = a[i-1][j][0];
		a[i][j][1] = a[i-1][j][1];
		if (j >= ball[i] && hp[i]+a[i-1][j-ball[i]][1] <= M){
			if (a[i-1][j-ball[i]][0]+1 > a[i][j][0]){
				a[i][j][0] = a[i-1][j-ball[i]][0]+1;
				a[i][j][1] = a[i-1][j-ball[i]][1] + hp[i];
			}
			else if (a[i-1][j-ball[i]][0]+1 == a[i][j][0])
				a[i][j][1] = min(a[i][j][1], a[i-1][j-ball[i]][1] + hp[i]);
		}
		if (a[i][j][0] > m1){
			m1=a[i][j][0]; m2=a[i][j][1];
		}
		else if (a[i][j][0] == m1) m2 = min(m2, a[i][j][1]);
	}
	printf("%d %d\n", m1, M-m2);
	return 0;
}