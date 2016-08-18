#include <cstdio>
using namespace std;

int gcd(int a, int b){
	int c;
	while (b){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

const int maxn=10000000;
int a[maxn];
int top;
class Bad{};
class OK{};

int main(){
	int n;
	scanf("%d", &n);
	top = 0;
	for (int i=2; i<=n; i++) {
		try {
			for (int j=0; j<top; j++)
				if (gcd(i, a[j]) != 1) throw Bad();
			throw OK();
		}
		catch (Bad) {continue;}
		catch (OK) {
			a[top++] = i;
			printf("%d\n", i);
		}
	}
	printf("\n");
	return 0;
}