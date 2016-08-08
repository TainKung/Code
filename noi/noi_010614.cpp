#include <cstdio>
#include <cstring>

const int maxn=40000;

class Big{
	int data[maxn], len;
public:
	Big(int x);
	Big& operator*=(int x);
	void print();
};

Big::Big(int x=0){
	len = 0;
	memset(data, 0, sizeof(data));
	while (x){
		data[len++] = x % 10;
		x /= 10;
	}
	if (!len) len=1;
}

Big& Big::operator*=(int x){
	int len = this->len;
	for (int i=0; i<len; i++) this->data[i] = this->data[i]*x;
	for (int i=0; i<len; i++){
		this->data[i+1] += this->data[i] / 10;
		this->data[i] %= 10;
	}
	while (this->data[len]){
		this->data[len+1] += this->data[len] / 10;
		this->data[len++] %= 10;
	}
	this->len = len;
	return *this;
}

void Big::print(){
	for (int i=this->len-1; i>=0; i--) printf("%c", this->data[i]+48);
	printf("\n");
}

int main(){
	int n;
	scanf("%d", &n);
	Big ans(1);
	for (int i=2; i<=n; i++) ans*=i;
	ans.print();
	return 0;
}