#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

#define INIT(Arr, Value) memset(Arr, Value, sizeof(Arr))
#define rep(Var, Start, End) for (Var=Start; Var!=End; Var++)
#define nrep(Type, Var, Start, End) for (Type Var=Start; Var!=End; Var++)
#define repr(Var, Start, End) for (Var=Start; Var!=End; Var--)
#define nrepr(Type, Var, Start, End) for (Type Var=Start; Var!=End; Var--)

// #define DEBUG 1
#ifdef DEBUG
#define debug(a) a
#else
#define debug(a)
#endif

const int kMax=10000;
struct Edge {
	int weight, point, next;
} edge[kMax];

int head[kMax], ord[kMax], low[kMax];
bool exist[kMax];
int n, m;
vector<vector<int> > result;
stack<int> dfsStack;
int index, vtail, etail;

inline int min(int a, int b) {
	return (a<b)? a:b;
}

void dfs(int u) {
	debug(printf("dfs(%d)\n", u);)
	dfsStack.push(u);
	exist[u] = 1;
	low[u] = ord[u] = ++index;
	for (int p=head[u]; p != -1; p=edge[p].next) {
		int v = edge[p].point;
		if (exist[v]) low[u] = min(low[u], ord[v]);
		else if (ord[v] == 0) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if (low[u] == ord[u]) {
		int t;
//		result.push_back(*(new vector<int>));
		do {
			t = dfsStack.top();
			dfsStack.pop();
			debug(printf("Pushing items into Vector[%d]\n", vtail);)
			result[vtail].push_back(t);
		} while (t != u);
		vtail++;
	}
	debug(printf("Exit dfs(%d)\n", u);)
}

void print() {
	nrep(int, i, 0, vtail) {
		nrep(vector<int>::iterator, j, result[i].begin(), result[i].end())
			printf("%d ", *j);
		printf("\n"); 
	}
}

void init() {
	INIT(head, -1);
	INIT(low, 0);
	INIT(exist, 0);
	INIT(ord, 0);
	index = vtail = etail = 0;
}

void addEdge(int u, int v, int w) {
	edge[etail].weight = w;
	edge[etail].point = v;
	edge[etail].next = head[u];
	head[u] = etail++;
}

int main() {
	scanf("%d%d", &n, &m);
	init();
	nrep(int, i, 0, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
	}
	nrep(int, u, 1, n+1) 
		if (ord[u] == 0) {
			dfs(u);
		}
	print();
	return 0;
}
