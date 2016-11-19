#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;

#define INIT(arr, value) memset(arr, value, sizeof(arr))

#define DEBUG
#ifdef DEBUG
#define debug(a) a
#else
#define debug(a)
#endif

const int kMaxN=10010, kMaxM=200010;
struct Graph{
    int head[kMaxM], tail;
    struct Edge {
        int v, next;
    } edge[kMaxM];
    Graph() {
        INIT(head, -1);
        tail = 0;
    }
    void addEdge(int u, int v) {
        edge[tail].v = v;
        edge[tail].next = head[u];
        head[u] = tail++;
    }
} graph, r_graph;
queue<int> list;
int visited[kMaxN], avail[kMaxN], time[kMaxN]; 
int s, t;

void bfs(Graph *g, int source) {
    list = queue<int>();
    list.push(source);
    time[source] = 0;
    INIT(visited, 0);
    visited[source] = 1;
    while (!list.empty()) {
        int u = list.front();
        list.pop();
        for (int p=g->head[u]; p!=-1; p=g->edge[p].next) {
            int v = g->edge[p].v;
            if (!visited[v] && avail[v]) {
                list.push(v);
                time[v] = time[u] + 1;
                visited[v] = 1;
            }
        }
    }
}

void erase(int u) {
    avail[u] = 0;
    for (int p=r_graph.head[u]; p!=-1; p=r_graph.edge[p].next)
        avail[r_graph.edge[p].v] = 0;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=0, u, v; i<m; i++) {
        scanf("%d%d", &u, &v);
        graph.addEdge(u, v);
        r_graph.addEdge(u, v);
    }
    scanf("%d%d", &s, &t);
    bfs(&r_graph, t);
    debug(for (int i=1; i<=n; i++) printf("%d ", visited[i]); printf("\n");)
    for (int i=1; i<=n; i++) if (!visited[i]) erase(i);
    debug(for (int i=1; i<=n; i++) printf("%d ", avail[i]); printf("\n");)
    bfs(&graph, s);
    printf("%d\n", (visited[t])? time[t]:-1);
    return 0;
}
