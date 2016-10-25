#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int kMax=50000;
int a[kMax];
bool stone[kMax];

int main() {
	int l, s, t, m;
	scanf("%d%d%d%d", &l, &s, &t, &m);
	int temp;
	for (int i=0; i<m; i++) {
		scanf("%d", &temp);
		stone[temp] = 1;
	}
	memset(a, 127, sizeof(a));
	a[0] = 0;
	for (int i=s; i<=l+t-1; i++) {
		for (int j=i-s; j>=i-t && j>=0; j--) 
			if (a[i] > a[j]) a[i] = a[j];
		if (stone[i]) a[i]++;
	}
	int result = INT_MAX;
	for (int i=l; i<=l+t-1; i++) 
		if (a[i] < result) result = a[i];
	printf("%d\n", result);
	return 0;
}