#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

#define DEBUG
#ifdef DEBUG
#define debug(a) a
#else
#define debug(a)
#endif

#define INIT(arr, value) memset(arr, value, sizeof(arr))

const int kMax=100010;
priority_queue<int> heap;

int main() {
    int n, m, q, u, v, t;
    scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
    double p = u * 1.0 / v;
    int grow = m * q;
    for (int i=0, t; i<n; i++) {
        scanf("%d", &t);
        heap.push(t + grow);
    }
    for (int i=1; i<=m; i++, grow-=q) {
        int cut = heap.top() - grow;
        heap.pop();
        int x1 = int(cut * p), x2 = cut - x1;
        x1 += grow - q;
        x2 += grow - q;
        heap.push(x1);
        heap.push(x2);
        if (i % t == 0) printf("%d ", cut);
    }
    printf("\n");
    for (int i=1; !heap.empty(); i++) {
        if (i % t == 0) printf("%d ", heap.top());
        heap.pop();
    }
    printf("\n");
    return 0;
}
