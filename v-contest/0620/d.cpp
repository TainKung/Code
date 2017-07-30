#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

#define DEBUG 1
#define $ if (DEBUG)
#define init(arr, value) memset(arr, value, sizeof(arr))

const int kMax = 1000;
char map[kMax+1][kMax+1];
int low[kMax], high[kMax], pos[kMax];
int h, w, limit;

struct Co {
  int x, y;
  Co(int _x=0, int _y=0) {
    x = _x; y = _y;
  }
};

queue<Co> list;

const int DOWN = 1;
const int UP = -1;
bool bfs(int d) {
  init(pos, 0);
  while (!list.empty()) {
    Co p = list.front();
    list.pop();
    if (d == DOWN && p.y == h - 1) return 1;
    if (map[p.y+d][p.x] != '.') {
      if (d == DOWN && p.y > low[p.x]) {
        low[p.x] = p.y;
      } else if (d == UP && p.y < high[p.x]) {
        high[p.x] = p.y;
      }
      continue;
    }
    int l = max(max(0, p.x - limit), pos[p.y+1]);
    int r = min(p.x + limit, w-1);
    int i;
    for (i = p.x - 1; i >= l && map[p.y+d][i] == '.'; i--)
      list.push(Co(i, p.y+d));
    for (i = p.x; i <= r && map[p.y+d][i] == '.'; i++)
      list.push(Co(i, p.y+d));
    pos[p.y+1] = i;
  }
  return 0;
}

int solve() {
  init(low, -1);

  for (int i = 0; i < w; i++)
    if (map[0][i] == '.') list.push(Co(i, 0));
  if (bfs(DOWN)) return 0;

  for (int i = 0; i < w; i++) {
    high[i] = h;
    if (map[h-1][i] == '.') list.push(Co(i, h-1));
  }
  bfs(UP);

  int ans = h;
  for (int i = 0, delta = high[0] - low[0]; i < w; i++, delta = high[i] - low[i])
    if (delta > 0 && delta < ans) ans = delta;
  return ans;
}

int main() {
  while (scanf("%d%d%d", &h, &w, &limit) > 0) {
    for (int i = 0; i < h; i++)
      scanf("%s", map[i]);
    printf("%d\n", solve());
  }
  return 0;
}
