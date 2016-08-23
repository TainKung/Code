// https://vijos.org/p/1097
#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

const int maxn=10000;
int a[maxn];
deque<int> b;

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", a+i);
	sort(a, a+n);
	int top = 2, ans = a[0] + a[1];
	b.push_back(ans);
	while (top != n) {
		if ((top == n-1 || b[0] <= a[top+1]) && (b.size() == 1 || a[top] <= b[1])) {
			ans += b.front() + a[top];
			b.push_back(b.front() + a[top++]);
			b.pop_front();
		} else if (a[top+1] < b.front()) {
			ans += a[top] + a[top+1];
			b.push_back(a[top] + a[top+1]);
			top += 2;
		} else if (b[1] < a[top]) {
			ans += b[0] + b[1];
			b.push_back(b[0] + b[1]);
			b.pop_front(); b.pop_front();
		}
	}
	while (b.size() != 1) {
		ans += b[0] + b[1];
		b.push_back(b[0] + b[1]);
		b.pop_front(); b.pop_front();
	}
	printf("%d\n", ans);
	return 0;
}