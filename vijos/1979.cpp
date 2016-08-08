#include<iostream>

using namespace std;
const int maxn=200000;

int aim[maxn],dis[maxn]={0},root[maxn];
int fa[maxn];
int ans=maxn+1;

int father(int p){
    if (fa[p]==p) return p;
    fa[p]=father(fa[p]);
    return fa[p];
}

void add(int a,int b){
    fa[father(b)]=father(a);
}

void work(int p){
    int i=1;
    dis[p]=i;
    while (true){
	p=aim[p];
	i++;
	if (dis[p]>0){
	    if (i-dis[p]<ans)
		ans=i-dis[p];
	    break;
	}
	else dis[p]=i;
    }
}

int main(){
    int n,i;

    cin>>n;
    for (i=0;i<n;i++) fa[i]=i;
    for (i=0;i<n;i++){
	cin>>aim[i];
	add(i,--aim[i]);
    }

    int p=0;
    for (i=0;i<n;i++)
	if (fa[i]==i)
	    root[p++]=i;

    for (i=0;i<p;i++) work(root[i]);
    cout<<ans<<"\n";

    return 0;
}
