#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100;
int a[maxn];
bool b[maxn];

int main(){
	int n;
	scanf("%d", &n);
	memset(b, 1, sizeof(b));
	for (int i=0; i<n; i++) scanf("%d", a+i);
	int ans=0;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			for (int k=0; k<n; k++)
				if (b[k] && (a[k] == a[i] + a[j])){
					ans++; b[k] = 0;
				}
	printf("%d\n", ans);
	return 0;
}
