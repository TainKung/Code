#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

class number{
	int data[50],len,k;
public:
	number(int ik){
		memset(data,0,sizeof(int));
		k=ik;len=0;
	}
	bool isRe();
	void add();
	void print();
	friend void val(string s,number &a);
};

inline char toChar(int x){
	return (x<10)? '0'+x:'A'+x-10;
}

inline int toInt(char x){
	return (x<='9')? x-'0':x-'A'+10;
}

bool number::isRe(){
	int p=0,q=this->len-1;
	while (p<q && this->data[p++]==this->data[q--]);
	return p==q;
}

void number::add(){
	int p=0,q=this->len-1;
	const number temp=*this;
	while (q+1) this->data[p++]+=temp.data[q--];
	for (q=0;q<this->len;q++){
		this->data[q+1]+=this->data[q]/this->k;
		this->data[q]%=k;
	}
	if (this->data[this->len]) this->len++;
}

void number::print(){
	for (int i=this->len-1;i+1;i--)
		printf("%c",toChar(this->data[i]));
	printf("\n");
}

void val(string s,number &a){
	a.len=s.length();
	for (int i=0;i<a.len;i++) a.data[i]=toInt(s[a.len-i-1]);
}

int main(){
	cin.sync_with_stdio(false);
	string s;
	number a(10);
	cin >> s;
	val(s,a);
	a.print();
	a.add();
	a.print();
	return 0;
}