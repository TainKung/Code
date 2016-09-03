#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

class Token {
public:
	virtual int data() =0;
};

class Number {
private:
	int data;
public:
	int data() {return this->data; }
};

class Operator {
private:
	char ope;
	Token *
