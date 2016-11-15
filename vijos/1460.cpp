#include <cstdio>
#include <cstring>

#define DEBUG 1
#ifdef DEBUG
#define debug(a) a
#else
#define debug(a)
#endif

#define INIT(arr, value) memset(arr, value, sizeof(arr))

const int kMaxN=10010;
const int kMaxM=100010;
int n, m;

int head[kMaxN], etail;
int dis[kMaxN];
struct Edge {
	int time, point, next;
} edge[kMaxN];

void addEdge(int u, int v, int t) {
	edge[etail].point = v;
	edge[etail].time = t;
	edge[etail].next = head[u];
	head[u] = etail++;
}

int fa[kMaxN];

int father(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = father(fa[x]);
}

void unionSet(int a, int b) {
	a = father(a); b = father(b);
	if (a != b) fa[b] = a;
}

int rhead[kMaxM*2], rtail;
struct Req {
	int v, pos, next;
} req[kMaxM*2];
int ans[kMaxM], x[kMaxM], y[kMaxM];
bool visited[kMaxN];

void addReq(int u, int v, int pos) {
	req[rtail].v = v;
	req[rtail].pos = pos;
	req[rtail].next = head[u];
	head[u] = rtail++;
	
	req[rtail].v = u;
	req[rtail].pos = pos;
	req[rtail++].next = head[v];
	head[v] = rtail++;
}

void init() {
	for (int i=0; i<=n; i++) fa[i] = i;
	debug(for (int i=0; i<=n; i++) printf("%d ", fa[i]); printf("\n");)
	INIT(head, -1);
	INIT(rhead, -1);
	INIT(visited, 0);
	INIT(dis, 0);
	etail = rtail = 0;
}

void lca(int u) {
	debug(printf("lca(%d)\n", u);)
	for (int p=head[u]; p!=-1; p=edge[p].next) {
		int v = edge[p].point;
		debug(printf("on point %d, try point %d\n", u, v);)
		dis[v] = dis[u] + edge[p].time;
		lca(v);
		unionSet(u, v);
		debug(printf("unionSet(%d, %d)\n", u, v);)
		debug(for (int i=0; i<=n; i++) printf("%d ", fa[i]); printf("\n");)
	}
	visited[u] = 1;
	for (int p=rhead[u]; p!=-1; p=req[p].next)
		if (visited[req[p].v] == 1)
			ans[req[p].pos] = u;
	debug(printf("exit lca(%d)\n", u);)
}

debug(
void printEdge() {
	for (int i=0; i<=n; i++) {
		for (int p=head[i]; p!=-1; p=edge[p].next)
			printf("%d->%d\n", i, edge[p].point);
	}
}
)

int main() {
	debug(freopen("1460.in", "r", stdin);)
	scanf("%d%d", &n, &m);
	init();
	for (int i=1, a, b, t; i<n; i++) {
		scanf("%d%d%d", &a, &b, &t);
		addEdge(a, b, t);
	}
	debug(printEdge();)
	for (int i=0; i<m; i++) {
		scanf("%d%d", x+i, y+i);
		addEdge(x[i], y[i], i);
	}
	debug(for (int i=0; i<=n; i++) printf("%d ", fa[i]); printf("\n");)
	lca(1);
	debug(for (int i=0; i<=m; i++) printf("%d ", ans[i]); printf("\n");)
	debug(for (int i=0; i<=n; i++) printf("%d ", fa[i]); printf("\n");)
	debug(for (int i=0; i<=n; i++) printf("%d ", dis[i]); printf("\n");)
	int ans1=0, ans2=0;
	for (int i=0; i<m; i++) {
		if (ans[i] != x[i]) continue;
		ans1++;
		ans2 += dis[y[i]] - dis[x[i]];
	}
	printf("%d\n%d\n", ans1, ans2);
	debug(fclose(stdin);)
	return 0;
}
