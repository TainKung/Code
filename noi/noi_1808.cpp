// http://noi.openjudge.cn/ch0206/1808/
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int a[200+1][200+1];
  string sa, sb;
  int lena, lenb, ans;
  int i, j, p;
  cin.sync_with_stdio(false);
  while (cin >> sa >> sb) {
    memset(a, 0, sizeof(a));
    lena=sa.length(); lenb=sb.length();
    ans=0;
    for (i=1; i<=lena; i++) for (j=1; j<=lenb; j++){
      for (p=1; p<=j+1; p++) a[i][j] = max(a[i][j], a[i-1][p-1] + (p != j+1 && sa[i-1] == sb[p-1]));
      ans = max(ans, a[i][j]);
    }
    cout << ans << endl;
  }
  return 0;
}
