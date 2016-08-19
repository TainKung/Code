#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

class bigInt {
	std::vector<int> data;
public:
	bigInt();
	bigInt(bigInt a);
	bigInt(int a);
	void print() const;
	bigInt &operator=(bigInt a);
	bigInt &operator=(int a);
	bigInt operator+(bigInt a);
	bigInt operator-(bigInt a);
	bigInt operator*(bigInt a);
	bigInt operator/(bigInt a);
	bigInt &operator+=(bigInt a);
	bigInt &operator-=(bigInt a);
	bigInt &operator*=(bigInt a);
	bigInt &operator/=(bigInt a);
};