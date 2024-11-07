#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int dp(int arr[], int low, int high){
    int i = low;
    int j = high;
    int pivot = arr[low];
    while(i < j){
        while(arr[i] <= pivot && i < high){
            i++;
        }
        while(arr[j] > pivot && j > low){
            j--;
        }
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}

int rp(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivotindex = rand() % (high - low) + low;
    swap(arr[pivotindex], arr[low]);
    int pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        while (arr[j] > pivot && j > low)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}

void dsort(int arr[], int low, int high){
    if(low < high){
        int p = dp(arr, low, high);
        dsort(arr, low, p - 1);
        dsort(arr, p + 1, high);
    }
}

void rsort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = rp(arr, low, high);
        rsort(arr, low, p - 1);
        rsort(arr, p + 1, high);
    }
}

int main(){
    int arr1[] = {5,3,9,1,7};
    int arr2[] = {7, 2, 5, 1, 6};
    cout << "D sort: " << endl;
    cout << "orignal array: " << endl;
    print(arr1, 5);
    cout << "sorted array: " << endl;
    dsort(arr1, 0, 4);
    print(arr1, 5);

    cout << "R sort: " << endl;
    cout << "orignal array: " << endl;
    print(arr2, 5);
    cout << "sorted array: " << endl;
    dsort(arr2, 0, 4);
    print(arr2, 5);
}