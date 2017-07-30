// http://noi.openjudge.cn/ch0206/2421/ Vision 2.0
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=370;
int a[MAXN+1], b[MAXN+1];

template<class T> T max(T a, T b){ return (a>b)? a:b; }

int main(){
	int n, i;
	double rate;
	scanf("%d", &n);
	a[0]=100000; b[0]=0;
	while (n){
		for (i=1; i<=n; i++){
			scanf("%lf", &rate);
			a[i] = max(a[i-1], int(b[i-1]*rate*0.97));
			b[i] = max(b[i-1], int(a[i-1]/rate*0.97));
		}
		printf("%.2lf\n", a[n]/100.0);
		scanf("%d", &n);
	}
	return 0;
}
