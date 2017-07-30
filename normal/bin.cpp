#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

template<class T>
T* binarySearch(T *l, T *r, T key) {
  while (l < r) {
    T *p = l + (r - l) / 2;
    if (*p < key) {
      l = p + 1;
    } else if (*p > key) {
      r = p;
    } else {
      return p;
    }
  }
  return NULL;
}

int main() {
  int a[100];
  srand(time(NULL));
  for (int i = 0; i < 100; i++)
    a[i] = rand() % 10000;
  sort(a, &a[100]);
  for (int i = 0; i < 100; i++) 
    printf("%d ", a[i]);
  printf("\n");
  int c;
  while (scanf("%d", &c) > 0)
    if (int *result = binarySearch(a, &a[100], c))
      printf("%d\n", *result);
    else
      printf("Not Found!\n");
  return 0;
}
