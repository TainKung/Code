#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int n=4;
const int aim=24;
const double d=0.01L;
int a[n];
bool b[n];

class Success{};

inline bool check(){return !(b[0] || b[1] || b[2] || b[3]);}

void search(double ans){
	if (abs(ans-aim) <= d && check()) throw Success();
	for (int i=0; i<n; i++) if (b[i]){
		b[i] = 0;
		search(ans+a[i]);
		search(ans-a[i]);
		search(ans*a[i]);
		search(ans/a[i]);
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
		try {
			search(0);
		}
		catch(Success){
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
}