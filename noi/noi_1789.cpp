#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int n=4;
const int aim=24;
const double d=0.01L;
int a[n];
bool b[n];
// double s[n];
// int c[n];
// int d[n];
// int len;

class Success{};

void search(double ans){
	if (fabs(ans) <= d) throw Success();
	// if (ans == 0) {throw Success();}
	for (int i=0; i<n; i++) if (b[i]){
		b[i] = 0;
		// s[len] = ans;
		// d[len] = a[i];
		// c[len++] = 1;
		search(ans+a[i]);
		// c[len] = 2;
		search(ans-a[i]);
		// c[len] = 3;
		search(ans*a[i]);
		// c[len] = 4;
		search(ans/a[i]);
		// len--;
		b[i] = 1;
	}
}

int main(){
	while (1){
		int t = 0;
		for (int i=0; i<n; i++){
			scanf("%d", a+i);
			t += a[i];
		}
		if (!t) return 0;
		memset(b, 1, sizeof(b));
		// len = 0;
		try {
			search(aim);
		}
		catch(Success){
			printf("YES\n");
			// for (int i=0; i<n; i++) printf("%.4f->", s[i]);
			// printf("DONE\n");
			// for (int i=0; i<n; i++) printf("%d ", d[i]);
			// printf("\n");
			// for (int i=0; i<n; i++) printf("%d ", c[i]);
			// printf("\n");
			continue;
		}
		printf("NO\n");
	}
}