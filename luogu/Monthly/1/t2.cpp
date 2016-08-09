#include <cstdio>
#include <cstring>
using namespace std;

typedef long double LD;

struct Pair{
	LD a, b;
	Pair(LD _x, LD _y){a = _x; b = _y;}
}

struct Data{
	LD sum, pow;
	Data(LD _a, LD _b){sum = _a; pow = _b;}
	Data operator+(Data a);
	Data& operator+=(Data a);
	Data& operator+=(LD _a, LD _b);
};

Data Data::operator+(Data a){
	Data ans;
	ans.sum = this->sum + a.sum;
	ans.pow = this->pow + a.pow;
	return ans;
}

inline Data& operator+=(Data a){
	this->sum += a.sum;
	this->pow += a.pow;
	return *this;
}

inline Data& operator+=(Pair x){
	this->sum += x.a;
	this->pow += x.b;
	return *this;
}

struct Node{
	int l, r;
	Data data;
	long double flag;
};

const int maxn=(1 << 17)+1;
Node t[maxn];
LD a[maxn];

Data create(int p, int l, int r){
	if (l == r){
		t[p].l = l;
		t[p].r = r;
		t[p].flag = 0;
		t[p].data = Data(a[l], a[l]*a[l]);
		return t[p].data;
	}
	int mid = (l+r)/2;
	t[p].l = l; t[p].r = r; t[p].flag = 0;
	t[p].data += create(p << 1, l, mid) + create((p << 1)+1, mid+1, r);
	return t[p].data;
};

Data search(int p, int l, int r){
	if (t[p].l == l && t[p].r == r) return Data;
	int mid = (l+r)/2;
	if (t[p].flag != 0){
		t[2*p] += t[p].flag;
		t[2*p+1] += t[p].flag;
	}
}