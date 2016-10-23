#include <cstdio>

int pow1(int x, int n) {
	if (n == 1) return x;
	else {
		int c = pow1(x, n/2);
		if (n & 1)
			return c*c*x;
		else
			return c*c;
	}
}

int pow2(int x, int n) {
	int result = 1;
	for (; n != 0; n >>= 1) {
		if (n & 1) result *= x;
		x *= x;
	}
	return result;
}

int main() {
	int x, n;
	scanf("%d%d", &x, &n);
	printf("%d %d\n", pow1(x, n), pow2(x, n));
	return 0;
}
