#include <cstdio>
#include <cstring>
#include <cstdlib>

#define INIT(arr, value) memset(arr, value, sizeof(arr))

//#define DEBUG 1
#ifdef DEBUG
#define debug(a) a
#else
#define debug(a)
#endif

const int kMaxN=30010;
int ehead[kMaxN], dis[kMaxN], etail;
int visited[kMaxN];
struct Edge {
	int v, next;
} edge[kMaxN];

void addEdge(int u, int v) {
	edge[etail].v = v;
	edge[etail].next = ehead[u];
	ehead[u] = etail++;
	
	edge[etail].v = u;
	edge[etail].next = ehead[v];
	ehead[v] = etail++;
}

int fa[kMaxN];

int father(int x) {
	return (fa[x] == x)? x : fa[x] = father(fa[x]);
}

void unionSet(int a, int b) {
	a = father(a); b = father(b);
	if (a != b) fa[b] = a;
}

const int kMaxM=100010;
int rhead[kMaxM], rtail;
struct Req {
	int v, pos, next;
} req[kMaxM];
int ans[kMaxM], x[kMaxM], y[kMaxM];

void addReq(int u, int v, int pos) {
	req[rtail].v = v;
	req[rtail].pos = pos;
	req[rtail].next = rhead[u];
	rhead[u] = rtail++;
	
	req[rtail].v = u;
	req[rtail].pos = pos;
	req[rtail].next = rhead[v];
	rhead[v] = rtail++;
}

void init() {
	INIT(ehead, -1);
	INIT(rhead, -1);
	INIT(visited, -1);
	etail = rtail = 0;
}

void lca(int u) {
	debug(printf("Start lca(%d)\n", u);)
	visited[u] = 0;
	for (int p=ehead[u]; p!=-1; p=edge[p].next) {
		int v = edge[p].v;
		if (visited[v] != -1) continue;
		dis[v] = dis[u] + 1;
		lca(v);
		unionSet(u, v);
	}
	visited[u] = 1;
	for (int p=rhead[u]; p!=-1; p=req[p].next)
		if (visited[req[p].v] == 1)
			ans[req[p].pos] = father(req[p].v);
	debug(printf("Exit lca(%d)\n", u);)
}

debug(
void printGraph(int n) {
	for (int u=1; u<=n; u++)
		for (int p=ehead[u]; p!=-1; p=edge[p].next)
			printf("%d->%d\n", u, edge[p].v);
}
)

int main() {
	int n, m;
	scanf("%d", &n);
	init();
	for (int i=0, u, v; i<n-1; i++) {
		scanf("%d%d", &u, &v);
		addEdge(u, v);
	}
	debug(printGraph(n);)
	scanf("%d", &m);
	int t1;
	scanf("%d", &x[0]);
	for (int i=1; i<=n; i++) fa[i] = i;
	for (int i=0; i<m-1; i++, x[i]=y[i-1]) {
		scanf("%d", y+i);
		addReq(x[i], y[i], i);
	}
	dis[1] = 0;
	lca(1);
	long long total=0;
	for (int i=0; i<m-1; i++)
		total += dis[x[i]] + dis[y[i]] - (dis[ans[i]] << 1);
	printf("%lld\n", total);
	return 0;
}
