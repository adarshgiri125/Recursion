#include<iostream>
using namespace std;
void subset(int index,vector<int> &arr,int sum,vector<int> &ds){
    if(index == arr.size()){
        cout<< sum << " ";
         return;
    }
   

    ds.push_back(arr[index]);
    sum+=arr[index];
    subset(index+1,arr,sum,ds);
    
    sum-=arr[index];
    ds.pop_back();
    subset(index+1,arr,sum,ds);
}

int main()
{

    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    
    vector<int> ds;
    int sum = 0;
    subset(0,arr,sum,ds);

    return 0;
}