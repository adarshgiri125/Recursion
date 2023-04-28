#include<iostream>
using namespace std;

void merge(int arr[], int s, int mid, int e)
{
    int size = e - s + 1;
    int* arr1 = new int[size];
    int left = s;
    int right = mid + 1;
    int k = 0;
    while (left <= mid && right <= e) {
        if (arr[left] <= arr[right]) {
            arr1[k] = arr[left];
            left++;
        }
        else {
            arr1[k] = arr[right];
            right++;
        }
        k++;
    }
    while (left <= mid) {
        arr1[k] = arr[left];
        k++;
        left++;
    }
    while (right <= e) {
        arr1[k] = arr[right];
        k++;
        right++;
    }
    for (int i = 0, j = s; i < size; i++, j++) {
        arr[j] = arr1[i];
    }
    delete[] arr1;
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e) {
        return;
    }
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}
int main()
{

    int arr[] = {5,4,3,2,1};
    int n = 5;
    int s = 0;
    int e = n-1;
    mergeSort(arr,s,e);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}