#include<iostream>
using namespace std;

bool palind(string &check,int s, int e){
    if(s>=e){
        return true;
    }
    if(check[s] != check[e]){
        return false;
    }
    return palind(check,s+1,e-1);
}
int main()
{

    string check = "kanak";
    int s = 0;
    int e = check.size() - 1;
    cout<<palind(check,s,e);
    return 0;
}