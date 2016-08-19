// http://noi.openjudge.cn/ch0407/6043/
// http://noi.openjudge.cn/ch0205/2971/
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxn=1000001;
int dis[maxn];

inline bool check(int x) {return x>=0 && x<maxn;}

int bfs(int s, int r) {
	queue<int> list;
	while (!list.empty()) list.pop();
	memset(dis, -1, sizeof(dis));
	list.push(s);
	dis[s] = 0;
	while (!list.empty()) {
		int p = list.front();
		if (p == r) return dis[r];
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
		if ((p & 1) == 0 && check(p >> 1) && dis[p >> 1] == -1) {
			list.push(p >> 1);
			dis[p >> 1] = dis[p] + 1;
		}
	}
	return dis[r];
}

int main() {
	int n, k, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		printf("%d\n", bfs(n, k) + bfs(k, n));
	}
	return 0;
}