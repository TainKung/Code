#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

class Number{
	int k,len,data[50];
public:
	Number(int ik){
		k=ik; len=1;
		memset(data,0,sizeof(data));
	}
	void print();
	Number& add();
	bool isRe();
	friend void val(string s, Number &a);
};

inline char toChar(int x){
	return (x<=9)? x+'0':x-10+'A';
}

inline int toInt(char x){
	return (x<='9')? x-'0':x-'A'+10;
}

void Number::print(){
	for (int i=this->len-1; i+1; i--)
		printf("%c",toChar(this->data[i]));
	printf("\n");
}

bool Number::isRe(){
	int p=0,q=this->len-1;
	while (p<q && this->data[p] == this->data[q]){
		p++; q--;
	}
	return p>=q;
}

Number& Number::add(){
	Number temp=*this;
	for (int i=0; i<this->len; i++){
		this->data[i] += temp.data[this->len-i-1];
		this->data[i+1] += this->data[i]/this->k;
		this->data[i] %= this->k;
	}
	if (this->data[this->len]) this->len++;
	return *this;
}

void val(string s, Number &a){
	a.len=s.length();
	for (int i=0;i<a.len;i++)
		a.data[i]=toInt(s[a.len-i-1]);
}

int main(){
	cin.sync_with_stdio(false);
	string s;
	int k,i;
	cin >> k;
	Number a(k);
	cin >> s;
	val(s,a);
	for (i=0; !a.isRe() && i<=31; i++) a.add();
	if (i<=30) printf("STEP=%d\n",i);
	else printf("Impossible!\n");
	return 0;
}