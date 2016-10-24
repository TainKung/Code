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

int main() {
	int l, s, t, m;
	scanf("%d", &l);
	scanf("%d%d%d", &s, &t, &m);
	for (int i=0; i<m; i++)
		scanf("%d", stone+i);
	a[0] = 0;
	int p = 0;
	sort(stone, stone+m);
	for (int i=s; i<=l+t-1; i++) {
		a[i & kM] = INT_MAX;
		for (int j=i-s; (j>=i-t) && (j>=0); j--)
			if (a[i & kM] > a[j & kM])
				a[i & kM] = a[j & kM];
		if (stone[p] == i) {
			a[i & kM]++;
			p++;
		}
	}
	int result = INT_MAX;
	for (int i=l; i<=l+t-1; i++) 
		if (a[i & kM] < result)
			result = a[i & kM];
	printf("%d\n", result);
	return 0;
}