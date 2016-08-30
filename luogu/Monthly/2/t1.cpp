#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn=20;
int seedA[3], seedB[3];
int count[maxn][maxn];
long double dis[maxn][maxn];

void makeData(int n, int seedA[], int seedB[]) {
	long long x=0, y=0, z=0;
	double a, b; 
	const int rp = 2333333;
	for (int i=0; i<n; i++) {
		x = (y * seedA[0] + seedB[0]) % rp;
		y = (z * seedA[1] + seedB[1]) % rp;
		z = (x * seedA[2] + seedB[2]) % rp;
		a = x % 20 + y % 10 / 10.0 + z % 10 / 100.0;

		x = (y * seedA[0] + seedB[0]) % rp;
		y = (z * seedA[1] + seedB[1]) % rp;
		z = (x * seedA[2] + seedB[2]) % rp;
		b = x % 20 + y % 10 / 10.0 + z % 10 / 100.0;

		dis[int(a)][int(b)] += a + b - int(a) - int(b);
		++count[int(a)][int(b)];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<3; i++) scanf("%d %d", seedA+i, seedB+i);
	memset(dis, 0, sizeof(dis));
	memset(count, 0, sizeof(count));
	makeData(n, seedA, seedB);
	double sum = 0.0, num = 0.0;
	for (int x1=0; x1<maxn; x1++) for (int y1=0; y1<maxn; y1++)
	for (int x2=x1+1; x2<maxn; x2++) for (int y2=y1+1; y2<maxn; y2++) {
		num += count[x1][y1] * count[x2][y2];
		sum += (x2+y2-x1-y1) * count[x1][y1] * count[x2][y2] \
		     - dis[x1][y1] * count[x2][y2] + dis[x2][y2] * count[x1][y1];
	}
	if (num == 0.0) printf("0.00000\n");
	else printf("%.5lf\n", sum/num);
	return 0;
}