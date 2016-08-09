#include <stdio.h>
#include <string.h>
#include <limits.h>

const int maxn=10000;
class Heap{
	int heapTail, data[maxn+1];
public:
	Heap(){
		heapTail=0; memset(data,127,sizeof(data));
	}
	void insert(int x);
	int getTop();
	int size(){return heapTail;}
};

void swap(int &x,int &y){int t=x; x=y; y=t;}

void Heap::insert(int x){
	this->data[++this->heapTail] = x;
	for (int p=this->heapTail; p-1 && this->data[p] < this->data[p>>1]; p>>=1)
		swap(this->data[p], this->data[p>>1]);
}

int Heap::getTop(){
	this->data[0] = this->data[1];
	this->data[1] = this->data[this->heapTail];
	this->data[this->heapTail--] = INT_MAX;
	for (int p=2,t; p<= this->heapTail; p<<=1){
		t= (this->data[p] < this->data[p+1])? p:p+1;
		if (this->data[p>>1] > this->data[t])
			swap(this->data[p>>1], this->data[t]);
		p = t;
	}
	return this->data[0];
}

int main(){
	int n,i,t,ans=0;
	Heap h;
	scanf("%d",&n);
	for (i=0; i<n; i++){
		scanf("%d",&t); h.insert(t); 
	}
	while (h.size()-1) {
		t=h.getTop()+h.getTop();
		ans+=t; h.insert(t);
	}
	printf("%d\n",ans);
	return 0;
}