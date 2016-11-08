#include <cstdio>
#include <cstring>

int main() {
    char s1[1000], s2[1000];
    scanf("%s%s", s1, s2);
    printf("%s\n%s\n", s1, s2);
    printf("%s\n", strncat(s1, s2, 5));;
    return 0;
}
