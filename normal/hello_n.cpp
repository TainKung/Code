#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char name[100];
    scanf("%[^\n]", name);
    printf("Hello, %s\n", name);
    return 0;
}
