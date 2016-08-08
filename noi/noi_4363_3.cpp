// http://noi.openjudge.cn/ch0401/4363/ Vision 3.0
#include <cstdio>
using namespace std;

class Member{
public:
	int number, score, strength;
	bool operator>(Member a) const;
	bool operator<(Member b) const;
};

bool Member::operator>(Member a) const{
	return this->score > a.score || (this->score == a.score && this->number < a.number);
}

bool Member::operator<(Member a) const{
	return this->score < a.score || (this->score == a.score && this->number > a.number);
}

template<class T> void swap(T &a, T &b){
	T t=a; a=b; b=t;
}

void qsort(Member a[], int l, int r){
	int i=l, j=r;
	Member p=a[(i+j)/2];
	while (i<=j){
		while (a[i]>p) i++;
		while (a[j]<p) j--;
		if (i<=j) swap(a[i++], a[j--]);
	}
	if (l<j) qsort(a, l, j);
	if (i<r) qsort(a, i, r);
}

void pk(Member a[], int n){
	for (int i=0; i<n; i+=2)
		if (a[i].strength > a[i+1].strength)
			a[i].score++;
		else
			a[i+1].score++;
}

const int MAXN=200000;
Member a[MAXN];

int main(){
	int n, r, q;
	scanf("%d %d %d", &n, &r, &q);
	n *= 2;
	for (int i=0; i<n; i++) scanf("%d", &a[i].score);
	for (int i=0; i<n; i++){
		scanf("%d", &a[i].strength);
		a[i].number=i+1;
	}
	qsort(a, 0, n-1);
	while (r--){
		pk(a, n);
		qsort(a, 0, n-1);
	}
	printf("%d\n", a[q-1].number);
	return 0;
}