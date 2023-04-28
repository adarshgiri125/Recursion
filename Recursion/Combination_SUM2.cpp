#include<iostream>
using namespace std;
void comb(int ind, vector<int> &value, int target, vector<int>&ds){
    if(ind == value.size()){
        if(target == 0){
            sort(ds.begin(),ds.end());
            for(auto i : ds){
                cout << i << " ";
            }
            cout << endl;
            
        }
        return;
    }
    
    if(value[ind] <= target){
        ds.push_back(value[ind]);
        comb(ind+1,value,target-value[ind],ds);
        ds.pop_back();
    }
    
    comb(ind+1,value,target,ds);

}
int main()
{
    vector<int> value;
    value.push_back(10);
    value.push_back(1);
    value.push_back(2);
    value.push_back(7);
    value.push_back(6);
    value.push_back(1);
    value.push_back(5);
    value.push_back(8);
    
    int target = 8;
    vector<int> ds;
    comb(0,value,target,ds);
    return 0;
}