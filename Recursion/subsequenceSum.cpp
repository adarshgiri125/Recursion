#include<iostream>
using namespace std;

void sub(int arr[], int n,int s,vector<int> &store,int sum, int su){
 if(s == n){
     if(su == sum){
       for(auto it : store){
        cout<<it<<" ";
       }
    
        cout<<endl;
     }
     return;
 }
 store.push_back(arr[s]);
 su += arr[s];
 sub(arr,n,s+1,store,sum,su);
 
 su -= arr[s];
 store.pop_back();
 sub(arr,n,s+1,store,sum,su);
 
}
int main()
{
    int n = 3;
    int arr[] = {1,2,1};
    int s = 0;
    int sum = 2;
    vector<int> store;
    sub(arr,n,s,store,sum,0);
    return 0;
}