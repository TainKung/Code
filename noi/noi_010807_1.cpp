#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100;
int a[maxn][maxn];

inline int min(int a, int b){ return (a<b)?a:b;}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", &a[i][j]);
	while (n>1) {
		printf("%d\n", a[1][1]);
		for (int i=0; i<n; i++){
			int temp=a[i][0];
			for (int j=0; j<n; j++) temp = min(temp, a[i][j]);
			for (int j=0; j<n; j++) a[i][j] -= temp;
		}
		for (int i=0; i<n; i++){
			int temp=a[0][i];
			for (int j=0; j<n; j++) temp = min(temp, a[j][i]);
			for (int j=0; j<n; j++) a[j][i] -= temp;
		}
		for (int i=1; i<n-1; i++){
			a[0][i] = a[0][i+1];
			a[i][0] = a[i+1][0];
		}
		for (int i=1; i<n-1; i++) for (int j=1; j<n-1; j++)
			a[i][j] = a[i+1][j+1];
		n--;
	}
	printf("0\n");
	return 0;
}