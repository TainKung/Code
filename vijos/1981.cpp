#include <cstdio>
#include <cstring>

const int kMax=50010;
int stone[kMax], dis[kMax];
int l, n, m;

bool check(int ans) {
    int t=0, p=0;
    for (int i=0; i<n; i++)
        if (dis[i]+p < ans) {
            p += dis[i];
            t++;
        } else {
            p = 0;
        }
    if (dis[n]+p < ans) t++;
    return t <= m;
}

int main() {
    scanf("%d%d%d", &l, &n, &m);
    stone[0] = 0;
    for (int i=1; i <= n; i++) {
        scanf("%d", stone + i);
        dis[i-1] = stone[i] - stone[i-1];
    }
    dis[n] = l - stone[n];
    int i=1, j=l, mid, time=0;
    while (i <= j) {
        mid = (i+j) >> 1;
        if (check(mid)) i = mid+1;
        else j = mid-1;
    }
    printf("%d\n", i-1);
    return 0;
}
