// http://noi.openjudge.cn/ch0402/9278/
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=10000;
class bigNum{
	int len, data[MAXN];
public:
	bigNum(int x);
	bigNum operator*(bigNum a) const;
	bigNum operator*(int a) const;
	bigNum& operator*=(int a);
	bigNum operator-(bigNum a) const;
	bigNum operator/(int a) const;
	friend bigNum fac();
	void print() const;
};

bigNum::bigNum(int x=0){
	memset(data, 0, sizeof(data));
	if (x==0) {len=1; return;};
	len=0;
	while (x){
		data[len++] = x % 10;
		x/=10;
	}
}

bigNum bigNum::operator*(bigNum a) const{
	bigNum t;
	for (int i=0; i<this->len; i++)
		for (int j=0; j<a.len; j++)
			t.data[i+j] += this->data[i] * a.data[j];
	t.len = this->len + a.len;
	for (int i=0; i<t.len; i++){
		t.data[i+1] += t.data[i] / 10;
		t.data[i] %= 10;
	}
	while (t.data[t.len-1]==0 && t.len>1) t.len--;
	return t;
}

bigNum bigNum::operator*(int a) const{
	bigNum t;
	t.len = this->len + 10;
	for (int i=0, p=0; i<t.len; i++){
		t.data[i] = this->data[i] * a +p;
		p = t.data[i] / 10;
		t.data[i] %= 10;
	}
	while (t.data[t.len-1]==0 && t.len>1) t.len--;
	return t;
}

bigNum& bigNum::operator*=(int a){
	this->len += 10;
	for (int i=0, p=0; i<this->len; i++){
		this->data[i] = this->data[i] * a +p;
		p = this->data[i] / 10;
		this->data[i] %= 10;
	}
	while (this->data[this->len-1]==0 && this->len>1) this->len--;
	return *this;
}

bigNum bigNum::operator-(bigNum a) const{
	bigNum t;
	for (int i=0; i<this->len; i++){
		t.data[i] += this->data[i] - a.data[i];
		if (t.data[i] < 0){
			t.data[i] += 10;
			t.data[i+1]--;
		}
	}
	t.len = this->len;
	while (t.data[t.len-1]==0 && t.len>1) t.len--;
	return t;
}

bigNum bigNum::operator/(int a) const{
	bigNum t;
	for (int i=this->len-1, p=0; i>=0; i--){
		p *= 10;
		t.data[i] = (this->data[i] + p) / a;
		p = (this->data[i] + p) % a;
	}
	t.len = this->len;
	while (t.data[t.len-1]==0 && t.len>1) t.len--;
	return t;
}

bigNum fac(int n){
	bigNum ans=bigNum(1);
	for (int i=2; i<=n; i++) ans*=i;
	return ans;
}

inline char i2c(int x){return x+'0';}

void bigNum::print() const{
	for (int i=this->len-1; i>=0; i--) printf("%c", i2c(this->data[i]));
	printf("\n");
}

void test(){
	int x,y;
	scanf("%d %d", &x, &y);
	bigNum(x).print();
	bigNum(y).print();
	(bigNum(x)-bigNum(y)).print();
	(bigNum(x)*bigNum(y)).print();
	(bigNum(x)*y).print();
	(bigNum(x)/y).print();
	fac(x).print();
	fac(y).print();
	bigNum a=bigNum(x);
	a*=y;
	a.print();
}

bigNum f[201];
int main(){
	// test();
	f[0]=bigNum(1);
	f[1]=bigNum(0);
	f[2]=bigNum(1);
	f[3]=bigNum(2);
	int n;
	scanf("%d", &n);
	for (int i=4; i<=n; i++){
		f[i]=fac(i);
		bigNum c=bigNum(1);
		for (int j=1; j<=i; j++){
			c = c * (i-j+1) / j;
			f[i] = f[i] - c * f[i-j];
		}
	}
	f[n].print();
	return 0;
}