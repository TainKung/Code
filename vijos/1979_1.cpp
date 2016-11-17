#include <cstdio>
#include <cstring>
#include <climits>

const int kMax=200010;
int next[kMax], visit[kMax], sign[kMax];
int n, ans, k;

inline int min(int a, int b) { return (a<b)? a:b; }

void dfs(int u) {
    k++;
    int v, m;
    for (v=u, m=1; visit[v] == 0; v=next[v], m++) {
        visit[v] = m;
        sign[v] = k;
    }
    if (visit[v] != 0 && sign[v] == sign[u]) {
        ans = min(ans, m-visit[v]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d", next+i);

    ans = INT_MAX; k = 0;
    memset(visit, 0, sizeof(visit));
    memset(sign, 0, sizeof(sign));

    for (int i=1; i<=n; i++)
        if (visit[i] == 0)
            dfs(i);
    printf("%d\n", ans);
    return 0;
}
