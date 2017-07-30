#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int rrand(int l, int r) {
  return rand() % (l-r+1) + l;
}

int main() {
  FILE *f = fopen("d.in", "w");
  srand((unsigned int) time(NULL));
  int n = rrand(100, 1000), m = rrand(100, 1000);
  int k = rrand(0, m);
  printf("Generate %dx%d matrix\n", m, n);
  fprintf(f, "%d %d %d\n", n, m, k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      fprintf(f, "%c", (rand() % 2)? '.' : 'x');
    fprintf(f, "\n");
  }
  fclose(f);
  return 0;
}
