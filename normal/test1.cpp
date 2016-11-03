#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char s1[100], s2[100];
    gets(s1);
    scanf("%[^\n]", s2);
    printf("%d, %d\n", strlen(s1), strlen(s2));
    return 0;
}