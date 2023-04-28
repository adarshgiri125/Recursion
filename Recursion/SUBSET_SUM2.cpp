#include<iostream>
#include<vector>
using namespace std;

void subset(int ind, int arr[],vector< vector<int> > &ans, vector<int> &ds ){
    ans.push_back(ds);
    for(int i = ind; i<ans.size(); i++){
       if( i!=ind && arr[i] == arr[i-1]) continue;
       ds.push_back(arr[i]);
       subset(ind+1,arr,ans,ds);
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
    subset(0,arr,ans,ds);
    return 0;
}