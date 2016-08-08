#include <stdio.h>
#include <iostream>
#include <vector>

template<class T> void swap(T* a,T* b){
    T c=*a;
    *a=*b;
    *b=c;
};

int main(){
    int a;
    int b;
    std::cin>>a>>b;
    if (a<b) swap<int>(&a,&b);
    std::cout<<a<<" "<<b<<"\n";

    return 0;
}
