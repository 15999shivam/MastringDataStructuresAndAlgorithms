#include<iostream>
using namespace std;

//fib iterative
int fibiterative(int n){
    if(n<2){
        return n;
    }
    else{
        int a=0,b=1,    x;
        for(int i=2;i<=n;i++){
            x=a+b;
            a=b;
            b=x;
        }
        return x;
    }
}

//fibsimplerecursion
int fibsimplerecursion(int n)
{
    if(n<2){
        return n;
    }
    else{
        return fibsimplerecursion(n-1)+fibsimplerecursion(n-2);
    }
}
 int f[10];
//fibwith memorisation to avoid excessive calls
int fibmemorisation(int n){
    if(n<2){
        f[n] = n;
        return n;
    }
    if(f[n-1]==-1)
        f[n-1] = fibmemorisation(n-1);
    if(f[n-2]==-1)
        f[n-2] = fibmemorisation(n-2);
        return f[n-1]+f[n-2];
    }
int main(){
    for(int i=0;i<10;i++)
    {

        f[i] = -1;
    }
    cout<<fibiterative(3)<<endl;
    cout<<fibsimplerecursion(3)<<endl;
    cout<<fibmemorisation(3)<<endl;
    return 0;
}
