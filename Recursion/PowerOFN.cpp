#include<iostream>
using namespace std;
int pow(int m,int n){
    if(n==0){
        return 1;
    }
    else{
        return m*pow(m,n-1);
    }
}

int powEfficent(int m,int n)
{
    if(n==0)
    {
        return 1;
    }
    else{
        if(n%2==0){
            return pow(m*m,n/2);
        }
        else{
            return m*pow(m*m,(n-1)/2);
        }
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<pow(m,n);
    cout<<powEfficent(m,n);
}
