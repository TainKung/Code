#include <iostream>
#include <string>

using namespace std;

int main(){
	cin.sync_with_stdio(false);
	const int maxn=100;
	string name[maxn];
	int money[maxn],total=0;
	int n,g1,g2,novel;
	char c1,c2;
	int max=0,p=0;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> name[i] >> g1 >> g2 >> c1 >> c2 >> novel;
		money[i]=0;
		if (g1>80 && novel) money[i]+=8000;
		if (g1>85 && g2>80) money[i]+=4000;
		if (g1>90) money[i]+=2000;
		if (g1>85 && c2=='Y') money[i]+=1000;
		if (g2>80 && c1=='Y') money[i]+=850;
		total+=money[i];
		// cout << g1 << g2 << c1 << c2 << novel;
		if (money[i]>max)
			max=money[p=i];
	}	
	cout << name[p] << "\n" << max << "\n" << total << "\n";

	return 0;
}