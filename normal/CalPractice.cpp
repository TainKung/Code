#include <cstdio>
#include <cstring>
#include <cstdlib>

class DivByZero {};

int getNum(char *&p);

int cal(char *&p) { // Checked.
	int a = getNum(p);
	while (*p != 0 && *p != ')')
		switch (*p) {
			case '+':return a + cal(++p);
			case '-':return a - cal(++p);
			case '|':return a | cal(++p);
			case '^':return a ^ cal(++p);
			case '*':{
				a *= getNum(++p);
				break;
			}
			case '/':{
				int b = getNum(++p);
				if (b == 0) throw DivByZero();
				a /= b;
				break;
			}
			case '&':{
				a &= getNum(++p);
				break;
			}
			case '<':{
				a <<= getNum(++p);
				break;
			}
			case '>':{
				a >>= getNum(++p);
				break;
			}
		}
	return a;
}

void removeSpace(char *p) { // Checked.
	char *q = p;
	while (*q != 0) {
		if (*q == ' ') {
			q++;
		} else {
			*p++ = *q++;
		}
	}
	*p = *q;
}

void simplify(char *p) {

}

void generate(char *p) {}

void output(char *p) { // Checked.
	for (; *p != 0; p++) {
		switch (*p) {
			case '+': case '*': {
				printf(" %c ", *p);
				break;
			}
			case '-': {
				if (*(p-1) < '0' || *(p-1) > '9') putchar(*p);
				else printf(" %c ", *p);
				break;
			}
			case '/': {
				printf(" div ");
				break;
			}
			case '&': {
				printf(" and ");
				break;
			}
			case '|': {
				printf(" or ");
				break;
			}
			case '^': {
				printf(" xor ");
				break;
			}
			case '<': {
				printf(" shl ");
				break;
			}
			case '>': {
				printf(" shr ");
				break;
			}
			default: putchar(*p);
		}
	}
	putchar('\n');
}

int getNum(char *&p) { // Checked.
	int result;
	if (*p == '(') {
		cal(++p);
	}
	sscanf(p, "%d", &result);
	// printf("%d\n", result);
	if (*p == '-') p++;
	while (*p >= '0' && *p <= '9') p++;
	return result;
}

int main() {
	char s[100];
	char *p = s;
	scanf("%[^\n]", p);
	// printf("%s\n", p);
	printf("%d\n", cal(p));
	output(s);
	// printf("%s\n", p);
	return 0;
}