// http://noi.openjudge.cn/ch0401/4363/ Vision 2.0
#include <cstdio>
using namespace std;

class Member{
public:
	int number, score, level;
	bool operator>(Member a) const{
		return this->score > a.score || (this->score == a.score && this->number < a.number);
	}
};

const int MAXN=200000;
Member a[MAXN];

template<class T> void swap(T &a, T &b){
	T t = a;
	a = b;
	b = t;
}

void qsort(Member a[], int l, int r){
	int i=l, j=r;
	const Member p=a[(i+j) / 2];
	while (i<=j){
		while (p > a[i]) i++;
		while (a[j] > p) j--;
		if (i<=j) swap(a[i++], a[j--]);
	}
	if (l<j) qsort(a, l, j);
	if (i<r) qsort(a, i, r);
}

void floating(Member a[], int n){
	for (int i=n-1; i>0; i--){
		if (a[i] > a[i-1]) swap(a[i],a[i-1]);
	}
	for (int i=n-1; i>0; i--){
		if (a[i] > a[i-1]) swap(a[i],a[i-1]);
	}
}

void count(Member a[], int n){
	for (int i=0; i<n; i+=2)
		if (a[i].level > a[i+1].level)
			a[i].score++;
		else
			a[i+1].score++;
}

int main(){
	int n, r, q;
	scanf("%d %d %d", &n, &r, &q);
	n*=2;
	for (int i=0; i<n; i++) scanf("%d", &a[i].score);
	for (int i=0; i<n; i++) scanf("%d", &a[i].level);
	for (int i=0; i<n; i++) a[i].number = i+1;
	qsort(a, 0, n-1);
	while (r--){
		count(a, n);
		floating(a, n);
	}
	printf("%d\n", a[q-1].number);
}