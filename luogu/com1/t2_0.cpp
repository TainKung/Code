#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const double pi=3.141592653589L;
const double e=2.71828182846L;

int main(){
	cin.sync_with_stdio(false);
	long long n;
	cin >> n;
	unsigned long long len = 0.5*log10(2*pi) + 0.5*log10(n) + n*log10(n/e);
	long long ans = 0;
	n /= 5;
	while (n){
		ans += n;
		n /= 5;
	}
	cout << len+1 << endl << ans << endl;
	return 0;
}