#include <cstdio>

const int kMax=12;
int spend[kMax];

int main() {
	for (int i=0; i<12; i++) scanf("%d", spend+i);
	int spare=0, saved=0, balance, flag=0;
	for (int i=0; i<12; i++) {
		balance = spare + 300 - spend[i];
		if (balance >= 0) {
			saved += balance / 100;
			spare = balance % 100;
		} else {
			spare = 0;
			if (flag == 0) flag = i+1;
		}
	}
	if (flag != 0) printf("-%d\n", flag);
	else printf("%d\n", spare + saved*120);
	return 0;
}
