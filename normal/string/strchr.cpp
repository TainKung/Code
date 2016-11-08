#include <cstdio>
#include <cstring>

int main() {
    char s1[1000], c2;
    scanf("%s | %c", s1, &c2);
    printf("%s %c\n", s1, c2);
    printf("%d\n", strchr(s1, c2)-s1);
    return 0;
}
