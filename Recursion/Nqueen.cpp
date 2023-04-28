#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int row, int col,vector<vector<int> > &board,int n ){
        int brow = row;
        int bcol = col;
        
        while(row>=0 && col>=0){
            if(board[row][col] == 1){
                return false;
            }
            row--;
            col--;
        }
        
        row = brow;
        col = bcol;
        
        while(col>=0){
            if(board[row][col] == 1){
                return false;
            }
            col--;
        }
        
        row = brow;
        col = bcol;
        
        while(row < n && col >=0){
            if(board[row][col] == 1){
                return false;
            }
            col--;
            row++;
        } 
        
        return true;
    }
    
    void solve(int col,vector<vector<int> > &ans,vector<vector<int> > &board,int n ){
        if(col == n){
          vector<int>temp;
          for(int col=0;col<n;++col){      //column
               for(int row=0;row<n;++row){  //row
                   if(board[row][col]==1){
                       temp.push_back(row+1);
                   }
               }
          }
          ans.push_back(temp);
           return;
        }
        
        for(int row = 0; row < n; row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 1;
                solve(col+1,ans,board,n);
                board[row][col] = 0 ;
                
            }
        }
        
    }
    vector<vector<int> > nQueen(int n) {
        vector<vector<int> > ans;
        vector<vector<int> > board(n,vector<int>(n,0));
        
        
        solve(0,ans,board,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int> > ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}

// to optimise this code you can use hashmap for the previous col queen check like this
// vector<int> left(n,0);
// vector<int> lowerDiagonal(2*n-1,0);
// vector<int> upperDiagonal(2*n-1,0);

// and before calling fn use this to mark 1 for queen --
// left[row] = 1;
// lowerDiagonal[row+col] = 1;
// upperDiagonal[(n-1) + (col - row)] = 1;
// after backtrack must sure that remove hashmap for like doing samething and put value = 0;

// left[row] = 0;
// lowerDiagonal[row+col] = 0;
// upperDiagonal[(n-1) + (col - row)] = 0;

