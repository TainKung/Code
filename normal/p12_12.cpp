#include <stdio.h>
#include <iostream>

using namespace std;

template<class T>
void changeLength(T* &a,int oldLength,int newLength){
    T* b=new T [newLength];
    for (int i=0;i<oldLength;i++)
	*b++=*a++;
    a=b;
}

int main(){
    return 0;
}
