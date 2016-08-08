// http://noi.openjudge.cn/ch0206/1808/ Vision 2.0
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

namespace my{
	inline int max(int a, int b){ return (a>b)? a:b; }
	inline int max(int a, int b, int c){
		if (c > b && c > a) return c;
		else return max(a, b);
	}
}

string sa, sb;
const int MAXN = 200;
int lena, lenb, a[MAXN+1][MAXN+1];
int i, j;

int main(){
	while (cin >> sa >> sb){
		lena = sa.length();
		lenb = sb.length();
		memset(a, 0, sizeof(a));
		for (i=1; i<=lena; i++) for (j=1; j<=lenb; j++)
			a[i][j] = my::max(a[i-1][j], a[i][j-1], a[i-1][j-1] + (sa[i-1] == sb[j-1]));
		cout << a[lena][lenb] << endl;
	}
	return 0;
}