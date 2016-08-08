// http://noi.openjudge.cn/ch0206/2988/
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <iostream>
using namespace std;

const int MAXN=1000;
long long a[MAXN+1][MAXN+1];

template<class T> void sawp(T &a, T &b){
	T t=a; a=b; b=t;
}

int main(){
	int n;
	cin >> n;
	while (n--){
		memset(a, 0, sizeof(a));
		string sa, sb;
		int i, j;
		cin >> sa >> sb;
		if (sa.length() < sb.length()) swap(sa, sb);
		int lena=sa.length(), lenb=sb.length();
		for (i=1; i<=lena; i++) a[i][0]=i;
		for (i=1; i<=lenb; i++) a[0][i]=i;
		for (i=1; i<=lena; i++) for (j=1; j<=lenb; j++){
			a[i][j] = min((sa[i-1] != sb[j-1]) + a[i-1][j-1], min(a[i-1][j], a[i][j-1]) + 1);
		}
		cout << a[lena][lenb] << endl;
	}
	return 0;
}