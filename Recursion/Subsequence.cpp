#include<iostream>
using namespace std;

void sub(int arr[], int n,int s,vector<int> &store){
 if(s == n){
    for(auto it : store){
        cout<<it<<" ";
    }
    if(store.size() == 0){
        cout<<"{}"<<" ";
    }
    cout<<endl;
    return;
 }
 store.push_back(arr[s]);
 sub(arr,n,s+1,store);

 store.pop_back();
 sub(arr,n,s+1,store);
 
}
int main()
{
    int n = 3;
    int arr[] = {3,1,2};
    int s = 0;
    vector<int> store;
    sub(arr,n,s,store);
    return 0;
}