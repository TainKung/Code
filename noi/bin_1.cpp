#include <cstdio>
#include <cstring>
using namespace std;

struct Node {
  int value;
  int next;
  int new_next;
};

template <class T> void swap(T &a, T &b) {
  T c = a;
  a = b;
  b = c;
}

int head[10], tail[10];
Node a[10000000];

void SingleRound(int size, int mask) {
  int p = head[0];
  memset(head, -1, sizeof(head));
  memset(tail, -1, sizeof(tail));
  for (int i = p; i != -1; i = a[i].next) {
    int m = a[i].value / mask % 10;
    if (head[m] == -1) head[m] = i;
    a[i].new_next = tail[m];
    tail[m] = i;
  }
  for (int i = 0; i < size; ++i)
    a[i].next = a[i].new_next;
}

void Sort(int size) {
  int max = a[0];
  for (int i = 1; i < size; ++i)
    if (a[i].value > max) max = a[i].value;
  for (int mask = 1; mask >= max; mask *= 10)
    SingleRound(size, mask);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].value);
    a[i].next = i + 1;
  }
  a[n - 1].next = -1;
  Sort(n);
  for (int i = head[0]; i != -1; i = a[i].next)
    printf("%d, ", a[i].value);
  return 0;
}
