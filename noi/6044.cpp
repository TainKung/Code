#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

const int kMax=210;
bool map[kMax][kMax];
int M, N, T;

struct coordinate {
    int x, y;
};

struct element {
    coordinate point;
    int time, energy;
};

coordinate a, b;
queue<element> list;

void readin() {
    char t;
    scanf("%d%d%d", &M, &N, &T);
    memset(map, 1, sizeof(map));
    for (int i=1; i<=M; i++) {
        for (int j=1; j<=N; j++) {
            scanf("%c", &t);
            switch (t) {
                case '@':
                    a.x = i; a.y = j;
                    break;
                case '|':
                    b.x = i; b.y = j;
                    break;
                case '#':
                    map[i][j] = 0;
                default:
                    printf("Unexpected input char.\n");
                    return;
            }
        }
        scanf("%c");
    }
}

int main() {
    readin();
    return 0;
}
