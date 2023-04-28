 vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> ds;

        solve(0,s,ans,ds);
        return ans;
    }

    void solve(int ind,string &s,vector<vector<string> >&ans, vector<string> &ds ){
       
       if(ind == s.size()){
           ans.push_back(ds);
           return ;
       }

       for(int i = ind; i<s.size(); ++i){
           if(isPalindrome(ind,i,s)){
               ds.push_back(s.substr(ind,i-ind + 1));
               solve(i+1,s,ans,ds);
               ds.pop_back();
           }
       }
    }

    bool isPalindrome(int start,int end, string &s){
       while(start <= end){
           if(s[start++] != s[end--]){
               return false;
           }
       }
       return true;
    }