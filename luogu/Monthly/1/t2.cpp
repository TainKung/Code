#include <cstdio>
#include <cstring>
using namespace std;

typedef long double LD;

struct Data {
	LD sum, pow;
	Data(LD a=0, LD b=0) {sum = a; pow = b;}
	Data& operator+=(Data a) {
		this->sum += a.sum;
		this->pow += a.pow;
		return *this;
	}
};

struct Node {
	int l, r;
	LD flag;
	Data data;
	int size() {return this->r - this->l + 1;}
};

const int maxn=10000000;
Node t[maxn];
LD x[100000];

Data update(int p, LD x) {
	LD dSum = t[p].size()*x;
	LD dPow = 2*x*t[p].data.sum + t[p].size()*x*x;
	Data temp(dSum, dPow);
	t[p].data += temp;
	t[p].flag += x;
	return temp;
}

void distFlag(int p) {
	update(2*p, t[p].flag);
	update(2*p+1, t[p].flag);
	t[p].flag = 0;
}

Data create(int p, int l, int r) {
	t[p].l = l;
	t[p].r = r;
	t[p].flag = 0;
	if (l == r) {
		t[p].data.sum = x[l];
		t[p].data.pow = x[l]*x[l];
	} else {
		int mid = (l+r) >> 1;
		t[p].data = create(2*p, l, mid);
		t[p].data += create(2*p+1, mid+1, r);
	}
	return t[p].data;
}

Data search(int p, int l, int r) {
	if (t[p].l >= l && t[p].r <= r) return t[p].data;
	if (t[p].l > r || t[p].r < l) return Data(0, 0);
	distFlag(p);
	Data ans;
	ans += search(2*p, l, r);
	ans += search(2*p+1, l, r);
	return ans;
}

Data modify(int p, int l, int r, LD x) {
	if (t[p].l >= l && t[p].r <= r) return update(p, x);
	if (t[p].l > r || t[p].r < l) return Data(0, 0);
	Data ans;
	ans += modify(2*p, l, r, x);
	ans += modify(2*p+1, l, r, x);
	t[p].data += ans;
	return ans;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%Lf", &x[i]);
	const int root = 1;
	create(root, 1, n);
	int ope, l, r;
	LD k;
	for (int i=1; i<=m; i++) {
		scanf("%d", &ope);
		switch (ope) {
			case 1: {
				scanf("%d %d %Lf", &l, &r, &k);
				modify(root, l, r, k);
				break;
			}
			case 2: {
				scanf("%d %d", &l, &r);
				printf("%.4Lf\n", search(root, l, r).sum / (r-l+1));
				break;
			}
			case 3: {
				scanf("%d %d", &l, &r);
				Data temp = search(root, l, r);
				printf("%.4Lf\n", (temp.pow - temp.sum * temp.sum / (r-l+1)) / (r-l+1));
				break;
			}
		}
	}
	return 0;
}