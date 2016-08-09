// vijos 1842
#include <stdio.h>
#include <string.h>

template<class T> void swap(T &x, T &y){T temp=x; x=y; y=temp;}

int mergeSort(int *l, int *r){
	int *mid= (r-l)/2+l, ans=0;
	if (mid > l) ans += mergeSort(l,mid);
	if (mid+1 < r) ans += mergeSort(mid+1,r);
	int *p=l, *q=mid+1;
	int *temp=new int[r-l+1];
	while (p<=mid && q<=r)
		if (*p<=*q) *temp++ = *p++;
		else {
			*temp++ = *q++;
			ans += mid-p+1;
		}
	while (p<=mid) *temp++ = *p++;
	while (q<=r) *temp++ = *q++;
	temp-=r-l+1;
	while (l<=r) *l++ = *temp++;
	// delete[] temp;
	return ans % 99999997;
}

void qsort(int a[], int l, int r, int order[]){
	int p=a[(l+r)/2];
	int i=l, j=r;
	while (i<=j){
		while (a[i]<p) i++;
		while (a[j]>p) j--;
		if (i<=j) {
			swap<int>(a[i],a[j]);
			swap<int>(order[i++],order[j--]);
		}
	}
	if (j>l) qsort(a,l,j,order);
	if (i<r) qsort(a,i,r,order);
}

int main(){
	int n,i;
	scanf("%d", &n);
	int a[n+1], b[n+1], oa[n+1], ob[n+1];
	for (i=0; i<n; i++) scanf("%d", a+i);
	for (i=0; i<n; i++) scanf("%d", b+i);
	for (i=0; i<n; i++) oa[i]=ob[i]=i;
	qsort(a,0,n-1,oa); qsort(b,0,n-1,ob);
	// for (i=0; i<n; i++) a[oa[i]]=i;
	// for (i=0; i<n; i++) b[ob[a[i]]]=i;
	for (i=0; i<n; i++) b[ob[i]]=oa[i];
	printf("%d\n",mergeSort(b,b+n-1));
	return 0;
}