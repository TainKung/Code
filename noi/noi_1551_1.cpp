#include <cstdio>
#include <hash_set>
#include <iostream>
using namespace std;

const int maxn=1000;
const signed small=0x80000000;
int a[maxn];

inline int max(int a, int b) {return (a>b)? a:b;}

int main(){
	hash_set<int> set;
	while (1) {
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++) {
			scanf("%d", a+i);
			set.incert(a[i]);
		}
		int ans = small;
		for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) for (int k=j+1; k<n; k++)
			if (set.find(temp = a[i] + a[j] + a[k]) != set.end())
				ans = max(ans, temp);
		if (ans == small) printf("no solution\n");
		else printf("%d\n", ans);
	}
	return 0;
}