#include <iostream>
#include <string.h>
#include <string>

using namespace std;

const int maxLen=6000;
class bigNum{
	int len,data[maxLen];
public:
	bigNum(){
		len=1;memset(data,0,sizeof(data));
	}
	const bigNum operator*(bigNum &a);
	friend void val(string s, bigNum &a);
	friend void print(bigNum a);
};

const bigNum bigNum::operator*(bigNum &a){
	bigNum temp;
	int i,j,t;
	for (i=0; i<this->len; i++)
		for (j=0; j<a.len; j++){
			t=this->data[i]*a.data[j];
			temp.data[i+j]+=t%10000;
			temp.data[i+j+1]+=t/10000;
		}
	int p=0; i=0;
	while (p || i<this->len+a.len-1){
		temp.data[i]+=p;
		p=temp.data[i]/10000;
		temp.data[i++]%=10000;
	}
	temp.len=++i;
	return temp;
}

inline int toInt(char x){ return x-'0';}
inline char toChar(int x){ return x+'0';}

void val(string s, bigNum &a){
	int sLen=s.length(), i=0, temp;
	a.len=(sLen+3)/4;
	for (int p=(sLen%4)? sLen%4:4, m=a.len-1; p<=sLen; p+=4, m--){
		temp=0;
		for (; i<p; i++) temp=temp*10 + toInt(s[i]);
		a.data[m]=temp;
	}
}

void print(bigNum a){
	string s, temp;
	int i, j;
	for (i=a.len-1; i+1; i--){
		temp="";
		for (j=1000; j; j/=10)
			temp+=toChar(a.data[i]/j % 10);
		s+=temp;
	}
	int sLen=s.length(); i=0;
	while (!toInt(s[i]) && i<sLen-1) i++;
	cout << s.substr(i,sLen-i) << endl;
}

int main(){
	cin.sync_with_stdio(false);
	string a,b;
	cin >> a; cin >> b;
	bigNum x,y;
	val(a,x); val(b,y);
	print(x*y);
	return 0;
}