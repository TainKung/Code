#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=1000;
int c[maxn], d[maxn], n;
bool a[maxn][maxn], b[maxn];

class Finish{};
class YES{};
class NO{};

int findRoot(){
	for (int i=1; i<=n; i++)
		if (b[i] && d[i] == 0) return i;
	return 0;
}

void dfs(int u){
	b[u] = 0;
	for (int v=1; v<=n; v++)
		if (a[u][v])
			if (b[v]) dfs(v);
			else throw NO{};
}

bool check(){
	for (int i=1; i<=n; i++) if (b[i]) return 0;
	return 1;
}

inline int max(int a, int b){return (a>b)?a:b;}

int main(){
	int x, y, k=0;
	try{
		while (1){
			k++; n=0;
			memset(a, 0, sizeof(a));
			memset(b, 0, sizeof(b));
			memset(c, 0, sizeof(c));
			memset(d, 0, sizeof(d));
			while (1){
				scanf("%d %d", &x, &y);
				if (x == 0) break;
				if (x < 0) throw Finish();
				a[x][y] = 1;
				b[x] = 1; b[y] = 1;
				c[x]++; d[y]++;
				n = max(n, max(x, y));
			}
			int root = findRoot();
			try{
				if (root) dfs(root);
				else throw NO();
				// if (check()) throw YES();
				// else throw NO();
				throw YES();
			}
			catch(YES){
				printf("Case %d is a tree.\n", k);
				continue;
			}
			catch(NO){
				printf("Case %d is not a tree.\n", k);
				continue;
			}
		}
	}
	catch(Finish){return 0;}
}