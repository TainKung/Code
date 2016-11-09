#include <cstdio>
#include <cstring>
#include <cstdlib>

const int kMax=210;
bool map[kMax][kMax];
int M, N, T;

struct coordinate {
    int x, y;
    coordinate(int _x=0, int _y=0) :x(_x), y(_y) {}
};

coordinate a, b;

void readin() {
    char t;
    scanf("%d%d%d", &M, &N, &T);
    memset(map, 1, sizeof(map));
    for (int i=1; i<=M; i++) {
        for (int j=1; j<=N; j++) {
            scanf("%c", &t);
            switch (t) {
                case '@':
                    a = coordinate(i, j);
                    break;
                case '|':
                    b = coordinate(i, j);
                    break;
                case '#':
                    map[i][j] = 0;
                default:
                    printf("Unexpected input char.\n");
                    return;
            }
        }
        scanf("%d")
    }
}

int main() {
    return 0;
}
