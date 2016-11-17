#include <cstdio>

int main() {
    char a, b, c;
    scanf("%[abcd]%[abcd]%[abcd]", &a, &b, &c);
    printf("%c%c%c\n", a, b, c);
    return 0;
}
