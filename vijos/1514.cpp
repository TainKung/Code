#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

#define INIT(arr, value) memset(arr, value, sizeof(arr))

//#define DEBUG 1
#ifdef DEBUG
#define debug(a) a
#else
#define debug(a)
#endif

const int kMax=200010;
int num[kMax], ans[kMax][21];
int n, m;

inline int max(int a, int b) {
	return (a>b)? a:b;
}

void st() {
	int maxLen = 21; //round(log2(n));
	debug(printf("MaxLen = %d\n", maxLen);)
	for (int i=0; i<n; i++) ans[i][0] = num[i];
	for (int j=1; j<=maxLen; j++) for (int i=0; i<n; i++) 
		if (i + (1 << (j-1)) < n)
			ans[i][j] = max(ans[i][j-1], ans[i + (1 << (j-1))][j-1]);
}

int getMax(int l, int r) {
	if (l == r) return num[l];
	else {
		int k = trunc(log2(r-l+1));
		return max(ans[l][k], ans[r-(1<<k)+1][k]);
	}
}

int main() {
	debug(freopen("1514.in", "r", stdin);)
	scanf("%d", &n);
//	cin.sync_with_stdio(false);
//	cin >> n;
	INIT(num, 0x80);
	debug(printf("%d\n", num[0]);)
	for (int i=0; i<n; i++) scanf("%d", num+i);
	st();
	scanf("%d", &m);
//	cin >> m;
	for (int i=0, l, r; i<m; i++) {
		scanf("%d%d", &l, &r);
		printf("%d\n", getMax(l-1, r-1));
	}
	debug(fclose(stdin);)
	return 0;
}
