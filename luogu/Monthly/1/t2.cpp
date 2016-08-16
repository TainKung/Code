#include <cstdio>
#include <cstring>
using namespace std;

typedef long double LD;

struct Data{
	LD sum, pow;
	Data(LD a=0, LD b=0){sum = a; pow = b;}
	Data& operator+=(Data a){
		this->sum += a.sum;
		this->pow += a.pow;
	}
}

struct Node{
	int l, r;
	LD flag;
	Data data;
}

const int maxn=10000000;
Node t[maxn];
LD x[100000];

void update(int p, LD x){
	t[p].pow += 2*x*t[p].sum + (r-l+1)*x*x;
	t[p].sum += (r-l+1) * x;
	t[p].flag += x;
}

void distFlag(int p){
	update(2*p, t[p].flag);
	update(2*p+1, t[p].flag);
	t[p].flag = 0;
}

Data create(int p, int l, int r){
	t[p].l = l;
	t[p].r = r;
	if (l == r){
		t[p].data.sum = x[l];
		t[p].data.pow = x[l]*x[l];
	} else {
		int mid = (l+r) >> 1;
		t[p].data = create(2*p, l, mid);
		t[p].data += create(2*p+1, mid+1, r);
	}
	return t[p].data;
}

Data search(int p, int l, int r){
	Data ans;
	if (t[p].l >= l && t[p].r <= r) return t[p].data;
	if (t[p].l > r || t[p].r < l) return Data(0, 0);
	distFlag(p);
	ans += search(2*p, l, r);
	ans += search(2*p+1, l, r);
	return ans;
}