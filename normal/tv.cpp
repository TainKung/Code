#include <cstdio>

const int kMaxN = 1e5 + 5;
int T, N;
long long G, P, sum, ans;
int dec, inc;
int v[kMaxN];

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d%lld%lld", &N, &G, &P);
    dec = inc = sum = 0;
    ans = 1;
    for (int i = 0, temp; i < N; i++) {
      scanf("%d", &temp);
      v[i] = temp;
      if (sum < 0 && temp > 0) {
        dec += sum;
        sum = temp;
      } else {
        sum += temp;
      }
    }
    if (sum > 0) inc += sum; else dec += sum;
    long long round = P / N;
    long long delta = inc + dec;
    if (delta <= 0) ans = G;
    else if (delta * (round - 1) >= G)
      ans = 0;
    else
      G =
  }
  return 0;
}
