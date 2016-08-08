// http://noi.openjudge.cn/ch0401/4363/ Vision 1.0
#include <cstdio>
using namespace std;

const int MAXN=200000;


struct Member{
	int number, score, level;
};

typedef Member* point;
point rank[MAXN], temp[MAXN];
Member peo[MAXN];

template<class T> void swap(T& a, T& b){
	T t=a;
	a=b;
	b=t;
}

void mergeSort(point a[], int l, int r){
	const int p = (l+r)/2;
	int i=l, j=p+1;
	if (i != p) mergeSort(a, i, p);
	if (r != r) mergeSort(a, j, r);
	int t=l;
	while (i <= p && j <= r)
		temp[t++] = (a[i]->score >= a[j]->score)? a[i++]:a[j++];
	while (i <= p) temp[t++] = a[i++];
	while (j <= r) temp[t++] = a[j++];
	for (t=l; t<=r; t++) a[t] = temp[t];
}

void count(point a[], int n){
	for (int i=0; i<n; i+=2)
		if (a[i]->level > a[i+1]->level)
			a[i]->score++;
		else
			a[i+1]->score++;
}

int main(){
	int n, r, q;
	scanf("%d %d %d", &n, &r, &q);
	n *= 2;
	for (int i=0; i<n; i++) scanf("%d", &peo[i].score);
	for (int i=0; i<n; i++) scanf("%d", &peo[i].level);
	for (int i=0; i<n; i++) peo[i].number = i+1;
	while (r--){
		for (int i=0; i<n; i++) rank[i] = &peo[i];
		mergeSort(rank, 0, n-1);
		count(rank, n);
	}
	for (int i=0; i<n; i++) rank[i] = &peo[i];
	mergeSort(rank, 0, n-1);
	printf("%d\n", rank[q-1]->number);
	for (int i=0; i<n; i++) printf("%d %d %d\n", rank[i]->number, rank[i]->level, rank[i]->score);
	return 0;
}