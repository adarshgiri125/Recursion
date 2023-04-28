#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subset(int ind, int arr[],vector< vector<int> > &ans, vector<int> &ds,int n ){
    for(auto i: ds){
        cout<< i << " ";
    }
    cout<<endl;
    ans.push_back(ds);
    for (int i = ind; i < n; i++) {
        if (i != ind && arr[i] == arr[i-1]) continue;
        ds.push_back(arr[i]);
        subset(i+1, arr, ans, ds,n);
        ds.pop_back();
    }
}
int main()
{

    int arr[] = {1,1,2,2,3,4};
    int n = 6;
    vector< vector<int> > ans;
    vector<int> ds;
    sort(arr,arr+n);
    subset(0,arr,ans,ds,n);
    
    return 0;
}