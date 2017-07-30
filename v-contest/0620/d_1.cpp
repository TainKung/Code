#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+10;
const double eps = 1e-6;
char a[1004][1004];
int dtu[1004][1004];
int utd[1004][1004];
int lt[1004][1004], rt[1004][1004];
///预处理每个位置最左最右可达的地方。
int n, m, k;
void init()
{
    memset(lt, -1, sizeof lt);
    memset(rt, -1, sizeof rt);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j]=='.'){
                lt[i][j] = lt[i][j-1]+1;
            }
        }
        for(int j = m; j >= 1; j--){
            if(a[i][j]=='.'){
                rt[i][j] = rt[i][j+1]+1;
            }
        }
    }
}
int Min(int a,int b)
{
    return a>b?b:a;
}
int Max(int a,int b)
{
    return a>b?a:b;
}
void dfsdtu(int x,int y)
{
    if(x==1){
        dtu[x][y] = 1;
        return ;
    }

    dtu[x][y] = 1;
    if(a[x-1][y]=='x') return ;
    for(int i = Max(y-lt[x-1][y],y-k); i <= Min(y+rt[x-1][y],y+k); i++){
        if(dtu[x-1][i]) break;
        dfsdtu(x-1,i);
    }
    for(int i = Min(y+rt[x-1][y],y+k); i >= Max(y-lt[x-1][y],y-k); i--){
        if(dtu[x-1][i]) break;
        dfsdtu(x-1,i);
    }
}
void dfsutd(int x,int y)
{
    if(x==n){
        utd[x][y] = 1;
        return ;
    }

    utd[x][y] = 1;
    if(a[x+1][y]=='x') return ;
    for(int i = Max(y-k,y-lt[x+1][y]); i <= Min(y+rt[x+1][y],y+k); i++){
        if(utd[x+1][i]) break;
        dfsutd(x+1,i);
    }
    for(int i = Min(y+rt[x+1][y],y+k); i >= Max(y-lt[x+1][y],y-k); i--){
        if(utd[x+1][i]) break;
        dfsutd(x+1,i);
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        for(int i = 1; i<= n; i++){
            scanf("%s",a[i]+1);
        }
        init();
        memset(dtu, 0, sizeof dtu);
        memset(utd, 0, sizeof utd);
        for(int i = 1; i <= m; i++){
            if(a[n][i]=='.'){
                dfsdtu(n,i);//由底向上
            }
        }
        for(int i = 1; i <= m; i++){
            if(a[1][i]=='.'){
                dfsutd(1,i);//由上到下
            }
        }

        int ans = n+1;
        for(int i = 1; i <= m; i++){
            int dt = n+1, ut = 0;
            for(int j = 1; j <= n; j++){
                if(dtu[j][i]){
                    dt = j;
                }
                if(utd[j][i]){
                    ut = j;
                }
                if(dt>ut){
                    ans = Min(ans,dt-ut);
                }
                ans = Min(ans,dt);
                ans = Min(ans,n+1-ut);
                if(dt==1||ut==n) ans = 0;
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}
