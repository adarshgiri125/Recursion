#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int i = s;
    int j = e;

    while(i < j){
        while(arr[i] <= pivot && i<=j-1){
            i++;
        }
        while(arr[j] > pivot && j>=i){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[s], arr[j]);
    return j;
}

void quicksort(int arr[], int s, int e){
    if(s < e){
       int ptindex = partition(arr,s,e);
       quicksort(arr,s,ptindex-1);
       quicksort(arr,ptindex+1,e);

    }
    
}
int main()
{
    int arr[] = {5,4,3,2,1};
    int n = 5;
    int s = 0;
    int e = n-1;

    quicksort(arr,s,e);

    for(int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }
    return 0;
}