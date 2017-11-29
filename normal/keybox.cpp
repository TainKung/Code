#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define STATE_IS_GET(x) ((bool)(x & 0x1000))
#define STATE_KEY_ID(x) ((unsigned short)(x & 0xfff))
#define STATE_TIME(x) ((unsigned short)(x >> 13))

inline unsigned int construct(unsigned short time, unsigned short id, bool method) {
  return (time << 13) | (method << 12) | id;
}

const int kMaxN = 1005;
int pos[kMaxN], result[kMaxN];
unsigned int state[kMaxN];
priority_queue<int, vector<int>, greater<int> > heap;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) pos[i] = i;
  for (int i = 0; i < k; i++) {
    int w, s, c;
    scanf("%d%d%d", &w, &s, &c);
    state[2 * i] = construct(s, w, 1);
    state[2 * i + 1] = construct(s + c, w, 0);
  }
  k *= 2;
  sort(&state[0], &state[k]);
  for (int i = 0; i < k; i++) {
    if (STATE_IS_GET(state[i])) {
      heap.push(pos[STATE_KEY_ID(state[i])]);
    } else {
      pos[STATE_KEY_ID(state[i])] = heap.top();
      heap.pop();
    }
  }
  for (int i = 1; i <= n; i++) result[pos[i]] = i;
  for (int i = 1; i <= n; i++)
    printf("%d ", result[i]);
  printf("\n");
  return 0;
}
