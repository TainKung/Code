#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int kMax = 16;
const int kM = 15;
int a[kMax];
int stone[110];

int jumpWithSameStep(int l, int step, int m) {
	for (int i=0; i<m; i++)
		if (stone[i] % step == 0)
			a[0]++;
	return a[0];
}

int cal(int s, int t) {
	if (s == t) return -1;
	int i=1;
	while ((i+1)*s - i*t > 1) i++;
	return i;
}

int main() {
	int l, s, t, m;
	scanf("%d", &l);
	scanf("%d%d%d", &s, &t, &m);
	for (int i=0; i<m; i++)
		scanf("%d", stone+i);
	if (s == t) { // 
		printf("%d\n", jumpWithSameStep(l, s, m));
		return 0;
	}
	memset(a, 127, sizeof(a));
	a[0] = 0;
	int p = 0;
	int sign = cal(s, t)*s;
	sort(stone, stone+m);
	stone[m] = l+t;
	for (int i=s; i<=l+t-1; i++) {
		a[i & kM] = 10000;
		for (int j=i-s; j>=i-t && j>=0; j--)
			if (a[i & kM] > a[j & kM])
				a[i & kM] = a[j & kM];
		if (stone[p] == i) {
			a[i & kM]++;
			p++;
		}
		if ((p == 0 || i == stone[p-1]+t) && stone[p]-t-i >= sign) {
			int minA = INT_MAX;
			for (int j=i; j>=0 && j>=i-t; j--) {
				if (a[j & kM] < minA) minA = a[j & kM];
			}
			for (int j=0; j<kMax; j++) a[j] = minA;
			i = stone[p]-t-1;
		}
	}
	int result = INT_MAX;
	for (int i=l; i<=l+t-1; i++) 
		if (a[i & kM] < result)
			result = a[i & kM];
	printf("%d\n", result);
	return 0;
}