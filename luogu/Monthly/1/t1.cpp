#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Edge{
	int v, next;
	bool data;
};

const int maxn=10000;
Edge way[6*maxn];
int point[5*maxn], dis[5*maxn];
int top, s, r;
queue<int> list;

bool bfs(){
	list.push(s);
	memset(dis, 0, sizeof(dis));
	dis[s] = 1;
	int t, p, v;
	while (!list.empty()){
		p = list.front(); list.pop();
		t = point[p];
		while (t){
			v = way[t].v;
			if (way[t].data && !dis[v]){
				list.push(v); dis[v] = dis[p]+1;
			}
			t = way[t].next;
		}
	}
	return dis[r];
}

void add(int u, int v, bool data){
	way[top].v = v;
	way[top].data = data;
	way[top].next = point[u];
	point[u] = top++;
}

void link(int u, int v){
	add(u, v, 1);
	add(u, v, 0);
}

bool dfs(int u){
	if (u == r) return 1;
	int t, v;
	t = point[u];
	while (t){
		v = way[t].v;
		if (way[t].data && dis[v] == dis[u] + 1 && dfs(v)){
			way[t].data = 0;
			if (way[t+1].v == u) way[t+1].data=1; else way[t-1].data=1;
			return 1;
		}
		t = way[t].next;
	}
	return 0;
}

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int s1=b, s2=s1+a, s3 =s2+a;
	int m; scanf("%d", &m);
	int x, y;
	s=0; r=s3+c+1;
	top = 1;
	memset(point, 0, sizeof(point));
	for (int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		link(s, y); link(y, s1+x); link(s1+x, s2+x);
	}
	scanf("%d", &m);
	for (int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		link(s2+x, s3+y); link(s3+y, r);
	}
	int ans=0;
	while (bfs()) ans+=dfs(s);
	printf("%d\n", ans);
}