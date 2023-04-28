#include<iostream>
#include <vector>
using namespace std;

void perm(int arr[],vector<int> &ds,int n,unordered_map<int , bool> flag){
    if(ds.size() == n){
        for(auto i : ds){
            cout<< i << " ";
        }cout<<endl;
        return ;

    }
    for(int i = 0; i<n; i++){
        if(flag[i] != 1){
           flag[i] = 1;
           ds.push_back(arr[i]);
           perm(arr,ds,n,flag);
           ds.pop_back();
           flag[i] = 0;
        }
        
    }
}
int main()
{

    int arr[] = {1,2,3};
    int n= 3;
    vector<int> ds;
    unordered_map<int , bool> flag;
    perm(arr,ds,n,flag);
    return 0;
}

// instead of map we can use array like int map[n] = {0};
// after that same approach will be carried out...