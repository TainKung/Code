#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Edge{
	int v, next;
	bool value;
}

int point[100010], dis[100010];
Edge way[1000000];
queue<int> list;
int top, r;

inline void add(int u, int v, int value){
	way[top].v = v;
	way[top].value = value;
	way[top].next = point[u];
	point[u] = top++;
}

inline void link(int u, int v){
	add(u, v, 1);
	add(v, u, 0);
}

bool bfs(){
	list.push(1);
	memset(dis, 0, sizeof(dis));
	dis[1] = 1;
	int p, t, v;
	while (!list.empty()){
		t = point[p = list.front()];
		list.pop();
		while (t){
			if (way[t].value && !dis[v = way[t].v]){
				list.push(v);
				dis[v] = dis[p] +1;
			}
			t = way[t].next;
		}
	}
	return dis[r];
}

bool dfs(int p){
	if (p == r) return 1;
	int t=point[p], v, a;
	while (t){
		if (way[t].value && dis[v = way[t].v] == dis[p]+1 && dfs(v)){
			way[t].value = 0;
			if (way[t+1].v == u) way[t+1].value = 1;
			else way[t-1].value = 1;
			return 1;
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a, b;
	for (int i=1; i<)
}