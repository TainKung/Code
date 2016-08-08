#include<stdio,h>
#include<iostream>
#include<cmath.h>

using namespace std;

class bigNum{
    private:
	int* a;
	int maxRow;
	bool signType;
    public:
	bigNum(int length=1){
	    a=new int [length];
	    maxRow=length;
	    signtype=false;
	}
	~bigNum(){delete[] a}
	bigNum& operator+(bigNum b);
	bigNum& operator+(int b);
	bigNum& operator-(bigNum b);
	bigNum& operator-(int b);
	bigNum& operator*(bigNum b);
	bigNum& operator*(int b);
	bigNum& operator/(bigNum b);
	bigNum& operator/(int b);
	char* output();
	bool isBig(a,b:big);
	class divByZero;
}

bigNum& bigNum::operator+(int b){
    if (signType){
	signType=false;
	*this=*this-b;
	signType
