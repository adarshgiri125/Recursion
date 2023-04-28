

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    bool isValid(vector<vector<int> > &mat, int i, int j, int k){
        for(int it = 0; it<9; it++){
            if(mat[it][j] == k)
                return false;
                
            if(mat[i][it] == k)
              return false;
              
              
            if(mat[3 * (i/3) + it/3 ][3 * (j/3) + it%3] == k){
                return false;
            }
            
        }
        return true;
    }
    bool solve(vector<vector<int> > &mat){
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    for(int k = 1; k<=9; k++){
                        if(isValid(mat,i,j,k)){
                            
                            mat[i][j] = k;
                            if(solve(mat) == true)
                            return true;
                            else mat[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    int isValid(vector<vector<int> > mat){
        int ans = solve(mat);
        if(ans == true){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int> > mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
