#include "./bigNum.h"

bigNum::bigNum() {
	data.clean();
	data.push_back(0);
}

bigNum::bigNum(bigInt a) {
	data = a;
}

bigNum::bigNum(int a) {
	data.clean();
	do {
		data.push_back(a % 10000);
		a /= 10000;
	} while (a != 0);
}
