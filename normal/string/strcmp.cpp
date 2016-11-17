#include <cstring>
#include <cstdio>

int main() {
    char s1[1000], s2[1000];
    scanf("%s%s", s1, s2);
    printf("%d\n", strncmp(s1, s2, 5));
    return 0;
}
