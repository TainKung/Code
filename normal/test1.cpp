#include <iostream>
#include <queue>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	queue<int> list;
	list.push(a);
	list.push(b);
	cout << list.empty() << endl << list.size() << endl << int(list.size()/sizeof(int)) << endl << list.front();
	return 0;
}