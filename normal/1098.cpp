#include <stdio.h>
#include <string.h>

using namespace std;

const int maxn=100;
int h[maxn+2],a[maxn+2],b[maxn+2];

int main(){
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<n+1;i++) scanf("%d",h+i);
	memset(a,0,sizeof(int));
	memset(b,0,sizeof(int));
	h[0]=h[n+1]=0;
	a[1]=b[n]=1;
	a[0]=b[n+1]=0;
	for (i=2;i<n+1;i++){
		for (j=i-1;j>0;j--)
			if (h[j]<h[i] && a[j]>a[i])
				a[i]=a[j];
		a[i]++;
	}
	for (i=n-1;i>0;i--){
		for (j=i+1;j<n+1;j++)
			if (h[j]<h[i] && b[j]>b[i])
				b[i]=b[j];
		b[i]++;
	}
	int max=0;
	for (i=1;i<n+1;i++)
		if (a[i]+b[i]>max) max=a[i]+b[i];
	printf("%d\n",n-max+1);

	return 0;
}