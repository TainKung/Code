#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;

double f1(ULL x){
	ULL k = x >> 1;
	if (!k) return 0;
	else return 4*f1(k) + ((x & 1)? 3*k:0);
}

double h1(ULL x){
	ULL k = x >> 1;
	if (!k) return 0;
	else if (x & 1) return 8*h1(k) + k*k + 2*f1(x-1) + x -1;
	else return 8*h1(k) + k*k;
}

double f2(ULL x){
	ULL k = x >> 1;
	if (!k) return x;
	else return 4*f2(k) + ((x & 1)? (k << 2)+1:k);
}

double h2(ULL x){
	ULL k = x >> 1;
	if (!k) return 0;
	else if (x & 1) return 8*h2(k) + k*(3*k+2) + 2*f2(x-1);
	else return 8*h2(k) + 3*k*k;
}

int main(){
	ULL n;
	cin >> n;
	double pow2 = n*n;
	printf("%.6e\n%.6e\n", h1(n)/pow2, h2(n)/pow2);
	// for (int i=1; i<=100000; i++) cout << h1(i) << endl;
	return 0;
}