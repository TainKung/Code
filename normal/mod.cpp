#include <iostream>
using namespace std;

int main(){
	int m, n, t;
	cin >> m >> n;
	int x=m, y=n;
	while (n != 0){
		t = m % n;
		m = n;
		n = t;
	}
	cout << int(x/m) << ' ' << int(y/m) << endl;
	return 0;
}