#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

long long C(int m, int n) {
  long long ans = 1;
  for (int i = 1; i <= m; i++)
    ans *= n - i + 1;
  for (int i = 2; i <= m; i++)
    ans /= i;
  return ans;
}

long long power2(int n) {
  long long ans = 1;
  return ans << n;
}

int main() {
  for (int n = 1; n <= 40; n++) {
    int t = (n + 1) / 2;
    long long ans = 0;
    for (int i = 0; i <= t; i++)
      ans += C(i, n - i + 1) * power2(n - i);
    printf("%ld, ", ans);
  }
  return 0;
}
