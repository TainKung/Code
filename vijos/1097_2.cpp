#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int kMax=10000;
priority_queue<int, vector<int>, greater<int> > heap;

int main() {
	int n, t, ans=0;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &t);
		heap.push(t);
	}
	for (int i=1; i<n; i++) {
		t = heap.top();
		heap.pop();
		t += heap.top();
		heap.pop();
		ans += t;
		heap.push(t);
	}
	printf("%d\n", ans);
	return 0;
}
