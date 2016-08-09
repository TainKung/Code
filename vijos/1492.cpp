#include <stdio.h>
#include <string.h>

const int maxn=250;
class bigNum{
	int len,data[maxn];
public:
	bigNum(){
		len=1;memset(data,0,sizeof(data));
	}
	bigNum(int x);
	bigNum operator-(int x) const;
	bigNum operator/(int x) const;
	bigNum &operator*=(int x);
	friend void print(bigNum x);
	friend bigNum power2(int x);
};

bigNum::bigNum(int x){
	len=0;
	memset(data,0,sizeof(data));
	while (x){
		data[len++]= x%10;
		x /= 10;
	}
}

bigNum bigNum::operator-(int x) const{
	bigNum temp=*this;
	temp.data[0]-=x;
	for (int i=0; i<temp.len && temp.data[i]<0; i++){
		temp.data[i]+=10; temp.data[i+1]--;
	}
	if (!temp.data[temp.len-1]) temp.len--;
	return temp;
}

bigNum bigNum::operator/(int x) const{
	bigNum temp;
	int p=0,i;
	for (i=this->len-1; i+1; i--){
		temp.data[i] = (this->data[i] + p*10) / x;
		p = (p*10 + this->data[i]) % x;
	}
	for (i=this->len-1; i && !temp.data[i]; i--);
	temp.len=i+1;
	return temp;
}

bigNum &bigNum::operator*=(int x){
	int i;
	for (i=0; i<this->len; i++) this->data[i] *= x;
	for (i=0; i<this->len; i++){
		this->data[i+1] += this->data[i] / 10;
		this->data[i] %= 10;
	}
	while (this->data[this->len]) this->len++; 
	return *this;
}

void print(bigNum x){
	for (int i=x.len-1; i+1; i--) printf("%d",x.data[i]);
	printf("\n");
}

bigNum power2(int x){
	bigNum ans;
	ans.data[0]=1;
	for (int i=0; i<x; i++) ans*=2;
	return ans;
}

int main(){
	int x;
	scanf("%d",&x);
	if (x<3) printf("%d\n",x);
	else print((power2(x+1)-((x & 1)?1:2))/3);
	return 0;
}