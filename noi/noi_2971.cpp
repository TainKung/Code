// http://noi.openjudge.cn/ch0205/2971/
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxn=100001;
int dis[maxn];

int bfs(int s, int r) {
	queue<int> list;
	while (!list.empty()) list.pop();
	memset(dis, -1, sizeof(dis));
	list.push(s);
	dis[s] = 0;
	while (!list.empty()) {
		int p = list.front();
		list.pop();
		if (check(p-1) && dis[p-1] == -1) {
			list.push(p-1);
			dis[p-1] = dis[p] + 1;
		}
		if (check(p+1) && dis[p+1] == -1) {
			list.push(p+1);
			dis[p+1] = dis[p] + 1;
		}
		if (check(p << 1) && dis[p << 1] == -1) {
			list.push(p << 1);
			dis[p << 1] = dis[p] + 1;
		}
	}
	return dis[r];
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", bfs(n, k));
	return 0;
}