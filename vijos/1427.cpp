#include <cstdio>
#include <cstring>
// #include <algorithm>
using namespace std;

#define DEBUG 1
#ifdef DEBUG
#define debug(a) a
#else
#define debug(a)
#endif

#define INIT(Arr, Value) memset(Arr, Value, sizeof(Arr))

const int kMax=10010;
int count[kMax], father[kMax], len[kMax];
int time, length;

int dis(int u) {
	if (father[u] == 0) return 0;
	else return dis(father[u]) + 1;
}

int lca(int a, int b) {
	int lp=dis(a), lq=dis(b), p=a, q=b;
	length = len[a] + len[b];
	debug(printf("%d %d\n", lp, lq);)
	time = 0;
	for (; lp > lq; lp--, p=father[p], length+=len[p], time+=count[p]) {}
	for (; lq > lp; lq--, q=father[q], length+=len[q], time+=count[q]) {}
	for (; p != q; p=father[p], q=father[q], length+=len[p]+len[q], time+=count[p]+count[q]) {
		debug(printf("%d %d\n", length, time);)
	}
	length -= len[p];
	time -= count[p];
}

int main() {
	debug(freopen("1427.in", "r", stdin);)
	int n, s, t;
	int tc, tp;
	char temp[300];
	INIT(count, 0);
	scanf("%d%d%d", &n, &s, &t);
	for (int i=0; i<n; i++) {
		scanf("%d%d%s", &tc, &tp, temp);
		father[tc] = tp;
		count[tp]++;
//		debug(printf("%s\n", temp);)
		len[tc] = strlen(temp);
	}
	debug(
		for (int i=1; i<=n; i++) printf("%d ", count[i]);
		printf("\n");
	)
	lca(s, t);
	printf("%d\n%d\n", length, time);
	debug(fclose(stdin);)
	return 0;
}
