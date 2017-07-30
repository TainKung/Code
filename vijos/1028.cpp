#include <cstdio>
#include <cstring>
#include <cstdlib>

#define DEBUG 1
#define $ if (DEBUG)

using namespace std;

const int kMax = 2000;
const int kMaxLen = 75;

char str[kMax][kMaxLen];
int ans[kMax];

int binSearch(int pos, const char* s) {
  $ printf("Call binSearch(%d, \"%s\")\n", pos, s);
  int l = 0, r = pos, p = (l + r) / 2;
  int result;
  while (l < r) {
    $ printf("    Searching (%d, %d)\n", l, r);
    int t = strcmp(s, str[p]);
    if (t > 0) {
      l = p + 1;
    } else if (t < 0) {
      r = p;
    } else {
      $ printf("Exit binSearch with result = %d\n\n", p);
      return p;
    }
  }
  $ printf("Exit binSearch with result = -1\n\n");
  return -1;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%s", str + i);
  $ {
    printf("All strings are read. They are:\n");
    for (int i = 0; i < n; i++)
      printf("%s\n", str[i]);
  }
  memset(ans, 0, sizeof(ans));
  int max = ans[0] = 1;
  char temp[75];
  for (int i = 1; i < n; i++) {
    strcpy(temp, str[i]);
    for (int p = strlen(str[i]); p >= 0; temp[--p] = 0)
      if (p == 0) {
        ans[i] = 1;
      } else {
        int j = binSearch(i, temp);
        if (j > 0) {
          ans[i] = ans[j] + 1;
          break;
        }
      }
    if (ans[i] > max) max = ans[i];
  }
  printf("%d\n", max);
  return 0;
}
