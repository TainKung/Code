#include <cstdio>
#include <cstring>
using namespace std;

const int m = 10007;
const int maxn = 1000;
const signed int min = 0x80000000;

struct Node {
	int value, next;
};

class HashList {
private:
	Node data[m];
	bool used[m];
	int top;
public:
	HashList();
	void push(int x);
	void clean();
	bool isExist(int x) const ;
	int operator[](int x) const {return this->data[x].value;}
	bool isUsed(int x) const {return this->used[x];}
};

inline HashList::HashList() {
	memset(this->data, -1, sizeof(this->data));
	memset(this->used, 0, sizeof(this->used));
}

void HashList::clean() {
	memset(this->data, -1, sizeof(this->data));
	memset(this->used, 0, sizeof(this->used));
}

void HashList::push(int x) {
	int p = (x % m + m) % m;
	if (!this->used[p]) {
		this->data[p].value = x;
		this->used[p] = 1;
	} else {
		for ( ; this->data[p].next != -1; p = (p+1) % m) {};
		int newPos;
		for (newPos = (p+1) % m; this->used[newPos]; newPos = (newPos+1) % m) {};
		this->data[newPos].value = x;
		this->data[p].next = newPos;
		this->used[newPos] = 1;
	}
}

bool HashList::isExist(int x) const {
	for (int p = (x % m + m) % m; p != -1 && this->used[p]; p = this->data[p].next)
		if (this->data[p].value == x) return 1;
	return 0;
}

inline int max(int a, int b) {return (a>b)? a:b;}

HashList hash;
int a[maxn];

int main(){
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		hash.clean();
		for (int i=0; i<n; i++) {
			scanf("%d", a+i);
			hash.push(a[i]);
		}
		int ans = min, temp;
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++)
				for (int k=j+1; k<n; k++)
					if (hash.isExist(temp = a[i] + a[j] + a[k]))
						ans = max(ans, temp);
		if (ans == min) printf("no solution\n");
		else printf("%d\n", ans);
	}
	return 0;
}