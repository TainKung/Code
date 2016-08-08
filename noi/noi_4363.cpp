// http://noi.openjudge.cn/ch0401/4363/
#include <cstdio>
#include <cstring>
using namespace std;

class Member{
public:
	int number, strength, score;
	Member(){
		number = strength = score = 0;
	}
};

template<class T> void swap(T* a, T* b){
	T t= *a;
	*a = *b;
	*b = t;
}

void qsort(Member a[], int l, int r){
	int i=l, j=r;
	const int p=a[(i+j) / 2].number;
	while (i<=j){
		while (a[i].number < p) i++;
		while (a[j].number > p) j--;
		if (i<=j) swap(&a[i++], &a[j--]);
	}
	if (l<j) qsort(a, l, j);
	if (i<r) qsort(a, i, r);
}

void mergeSort(Member a[], int l, int r, Member temp[]){
	const int p=(l+r)/2;
	if (l != p) mergeSort(a, l, p, temp);
	if (p+1 != r) mergeSort(a, p+1, r, temp);
	int i=l, j=p+1, t=l;
	while (i <= p && j <= r)
		temp[t++] = (a[i].score >= a[j].score)? a[i++]:a[j++];
	while (i <= p) temp[t++] = a[i++];
	while (j <= r) temp[t++] = a[j++];
	for (t=l; t<=r; t++) a[t] = temp[t];
}

void count(Member a[], int n){
	for (int i=0; i<n; i+=2)
		if (a[i].strength > a[i+1].strength)
			a[i].score++;
		else
			a[i+1].score++;
}

const int MAXN=200000;
Member a[MAXN], temp[MAXN];

int main(){
	int N, R, Q;
	scanf("%d %d %d", &N, &R, &Q);
	N *= 2;
	for (int i=0; i<N; i++) scanf("%d", &a[i].score);
	for (int i=0; i<N; i++) scanf("%d", &a[i].strength);
	for (int i=0; i<N; i++) a[i].number = i;
	while (R--){
		qsort(a, 0, N-1);
		mergeSort(a, 0, N-1, temp);
		count(a, N);
	}
	qsort(a, 0, N-1);
	mergeSort(a, 0, N-1, temp);
	printf("%d\n", a[Q-1].number+1);
	// for (int i=0; i<N; i++) printf("%d %d %d\n", a[i].number, a[i].strength, a[i].score);
	return 0;
}