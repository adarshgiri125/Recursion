#include<iostream>
using namespace std;

int sub(int arr[], int n,int s,int sum, int su){
 if(s == n){
     if(su == sum){
       return 1;
    
     }
     else return 0;
 }
 
 su += arr[s];
 int r = sub(arr,n,s+1,sum,su);
 
 su -= arr[s];
 
 int l = sub(arr,n,s+1,sum,su);
 
 return l + r;
}
int main()
{
    int n = 3;
    int arr[] = {1,2,1};
    int s = 0;
    int sum = 2;
    
    cout<<sub(arr,n,s,sum,0)<<endl;
    return 0;
}