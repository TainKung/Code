// http://noi.openjudge.cn/ch0206/2421/
#include <cstdio>

using namespace std;

const int MAXN=365;
double rate[MAXN];

int main(){
	int n, i;
	double can, dol;
	scanf("%d", &n);
	while (n){
		can=100000; dol=0;
		for (i=0; i<n; i++) scanf("%lf", rate+i);
		for (i=0; i<n; i++)
			if (dol*rate[i]*0.97 > can) can=dol*rate[i]*0.97;
			else if (dol*rate[i] < can*0.97) dol=can/rate[i]*0.97;
		printf("%.2lf\n", can/100.0);
		scanf("%d", &n);
	}
}