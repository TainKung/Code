// http://noi.openjudge.cn/ch0206/4978/
#include <cstdio>
using namespace std;

inline int max(int a, int b){ return (a>b)? a:b;}

int a[1001][501], ball[101], hp[101];

int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for (int i=1; i<=K; i++) scanf("%d %d", ball+i, hp+i);
	for (int i=1; i<=K; i++) for (int j=N; j>=1; j--) for (int k=M; k>=0; k--)
		a[j][k] = max(a[j][k], (j >= ball[i] && k >= hp[i])? a[j-ball[i]][k-hp[i]]+1:0);
	int m1=0, m2=0;
	for (int i=1; i<=M; i++)
		if (a[N][i] > m1){
			m1 = a[N][i];
			m2 = i;
		}
	printf("%d %d\n", m1, M-m2);
	return 0;
}