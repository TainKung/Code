#include <cstdio>

const int kMax=200;
const int result[5][5]={{ 0,-1, 1, 1,-1},
					   { 1, 0,-1, 1,-1},
					   {-1, 1, 0,-1, 1},
					   {-1,-1, 1, 0, 1},
					   { 1, 1,-1,-1, 0}}; 
int n, na, nb, sa, sb;
int a[kMax], b[kMax];

int main() {
	scanf("%d%d%d", &n, &na, &nb);
	for (int i=0; i<na; i++) scanf("%d", a+i);
	for (int i=0; i<nb; i++) scanf("%d", b+i);
	sa = sb = 0;
	int temp;
	for (int i=0; i<n; i++) {
		temp = result[a[i % na]][b[i % nb]];
		if (temp == 1) sa++;
		else if (temp == -1) sb++;
	}
	printf("%d %d\n", sa, sb);
	return 0;
}
