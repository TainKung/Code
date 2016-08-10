// http://noi.openjudge.cn/ch0307/2726/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn=1010;
int h[maxn], a[maxn], n, len, m, ans, k, t;

void swap(int &a, int &b){
	int t=a; a=b; b=t;
}

inline int min(int a, int b){ return (a<b)? a:b;}

void topAdd(int x){
	int p=2;
	h[1] += x;
	while (p <= len){
		if (p+1 <= len && h[p >> 1] > min(h[p], h[p+1])){
				p += (h[p+1]<h[p]);
				swap(h[p >> 1], h[p]);
				p <<= 1;
			}
		else if (h[p] < h[p >> 1]){
			swap(h[p], h[p >> 1]);
			p <<= 1;
		}
		else break;
	}
}

int sum(){
	int ans=0;
	for (int i=1; i<=len; i++) ans+=abs(h[i]-m);
	return ans;
}

int check(int k){
	memset(h, 0, sizeof(h));
	len = k;
	for (int i=n-1; i>=0; i--) topAdd(a[i]);
	return sum();
}

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", a+i);
	sort(a, a+n);
	m = a[n-1];
	ans = 1e9;
	for (int i=n; i; i--)
		if (ans > (t = check(i))){
			ans = t;
			k = i;
		}
	printf("%d\n", k);
}