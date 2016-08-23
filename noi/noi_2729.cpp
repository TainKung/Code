// http://noi.openjudge.cn/ch0304/2729/
#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		queue<int> a, b;
		a.push(2*n+1);
		b.push(3*n+1);
		scanf("%d", &n);
		int ans;
		for (int k=1; k != n; k++) {
			if (a.front() == b.front()) {
				ans = a.front();
				a.pop();
				b.pop();
			} else if (a.front() < b.front()) {
				ans = a.front();
				a.pop();
			} else {
				ans = b.front();
				b.pop();
			}
			a.push(2*ans+1);
			b.push(3*ans+1);
		}
		printf("%d\n", ans);
	}
	return 0;
}