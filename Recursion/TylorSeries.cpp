#include<iostream>
using namespace std;

//Simpletylor
double SimpleTylor(int x,int n){
    static double p=1,f=1;
    double result;
    if(n==0){
        return 1;
    }
    result = SimpleTylor(x,n-1);
    p = p*x;
    f = f*n;
    return (result+p/f);
}

//hornerRule
double tylorSeriresHorner(int x,int n){
    static double s = 1;
    if(n==0)
        return s;
        s = 1+x*1.0/n*1.0*s;
    return tylorSeriresHorner(x,n-1);
}

//tylor iterative
double tylorIterative(int x,int n){
    double s = 1;
    for(;n>0;n--)
    {
        s = 1+(1.0*x)/n*s;
    }
    return s;
}


int main(){
    cout<<SimpleTylor(1,10000)<<endl;
    cout<<tylorSeriresHorner(1,10000)<<endl;
    cout<<tylorIterative(1,10000)<<endl;
    return 0;
}
