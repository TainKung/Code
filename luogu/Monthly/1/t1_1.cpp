#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Edge{
	int v, next;
	bool data;
};

const int maxn=10001;
Edge way[10*maxn];
int point[5*maxn], dis[5*maxn];
int s, r, top;
queue<int> l;

bool bfs(){
	memset(dis, 0, sizeof(dis));
	while(!l.empty()) l.pop();
	l.push(s); dis[s]=1;
	int u, v;
	while (!l.empty()){
		u = l.front();
		l.pop();
		for (int t = point[u]; t; t = way[t].next)
			if (way[t].data && !dis[v = way[t].v]){
				l.push(v);
				dis[v] = dis[u] + 1;
			}
	}
	return dis[r];
}

inline void addEdge(int u, int v){
	way[top].v = v;
	way[top].data = 1;
	way[top].next = point[u];
	point[u] = top++;

	way[top].v = u;
	way[top].data = 0;
	way[top].next = point[v];
	point[v] = top++;
}

bool dfs(int u){
	if (u == r) return 1;
	int v;
	for (int t = point[u]; t; t = way[t].next)
		if (way[t].data && (dis[v = way[t].v] == dis[u] + 1) && dfs(v)){
			way[t].data = 0;
			if (way[t+1].v == u) way[t+1].data=1; else way[t-1].data=1;
			return 1;
		}
	return 0;
}

int main(){
	int n1, n2, n3;
	scanf("%d %d %d", &n1, &n2, &n3);
	const int s1=n2, s2=n1+n2, s3=n2+(n1 << 1);
	s = 0; r = s3+n3+1;
	int m, x, y;
	scanf("%d", &m);
	top = 1;
	memset(point, 0, sizeof(point));
	for (int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		addEdge(0, y); addEdge(y, s1+x); addEdge(s1+x, s2+x);
	}
	scanf("%d", &m);
	for (int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		addEdge(s2+x, s3+y); addEdge(s3+y, r);
	}
	int ans=0;
	while (bfs()) ans+=dfs(s);
	printf("%d\n", ans);
}