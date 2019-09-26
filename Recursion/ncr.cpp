#include<iostream>
using namespace std;

int fact(int n){
if(n==0)return 1;
return n*fact(n-1);
}

//simple
int ncr(int n,int r){
    int num,denm;
    num = fact(n);
    denm = fact(r)*fact(n-r);
    return num/denm;
}

//ncr pascal triangle
int Pncr(int n,int r){
    if(r==0  || n==r)
        return 1;
    return Pncr(n-1,r-1)+Pncr(n-1,r);
}

int main(){
    cout<<ncr(5,1)<<endl;
    cout<<Pncr(5,1)<<endl;
    return 0;
}
