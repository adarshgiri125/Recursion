#include<iostream>
using namespace std;

void reverse(int arr[], int n,int i, int e){
     
     if(i >= e){
        return;
     } 
     swap(arr[i],arr[e]);
     reverse(arr,n,i+1,e-1);
}
int main()
{
    int n = 6;
    int arr[] = {1,2,3,4,5,6};
    int i = 0;
    int e = n-1;
    reverse(arr,n,i,e);
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}