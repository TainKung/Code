#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

#define INIT(arr, value) memset(arr, value, sizeof(arr))
#define POW(x) ((x)*(x))

const int kMax=200010, kMod=10007;
int max1[kMax], max2[kMax], sum[kMax], psum[kMax], weight[kMax];
struct Edge {
    int u, v;
} edge[kMax];

void swap(int &a, int &b){
    int t=a;a=b;b=t;
}

inline int max(int a, int b) { return (a>b)? a:b; }

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n-1; i++) scanf("%d%d", &edge[i].u, &edge[i].v);
    for (int i=1; i<=n; i++) scanf("%d", weight+i);
    for (int i=0; i<n-1; i++) {
        int u = edge[i].u, v = edge[i].v;
        if (weight[u] > max1[v]) {
            max2[v] = max1[v];
            max1[v] = weight[u];
        } else if (weight[u] > max2[v])
            max2[v] = weight[u];
        sum[v] = (sum[v] + weight[u]) % kMod;
        psum[v] = (psum[v] + POW(weight[u])) % kMod;

        swap(u, v);
        if (weight[u] > max1[v]) {
            max2[v] = max1[v];
            max1[v] = weight[u];
        } else if (weight[u] > max2[v])
            max2[v] = weight[u];
        sum[v] = (sum[v] + weight[u]) % kMod;
        psum[v] = (psum[v] + POW(weight[u])) % kMod;
    }
    int maxest = 0, total = 0;
    for (int i=1; i<=n; i++) {
        maxest = max(maxest, max1[i] * max2[i]);
        total = (total + POW(sum[i]) - psum[i]) % kMod;
    }
    printf("%d %d\n", maxest, total);
    return 0;
}
