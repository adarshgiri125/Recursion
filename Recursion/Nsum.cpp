#include<iostream>
using namespace std;

void sum(int n,int summ){
    if(n < 1){
        cout<< summ <<endl;
        return;
    }
    sum(n-1,summ+n);
}


int main()
{
    int n;
    cin>>n;
    int summ = 0;
    sum(n,summ);
    return 0;
}