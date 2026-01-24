#include<iostream>
using namespace std;
void insertionsort(int arr[],int n)
{
    for(int i = 1;i<n;i++)
    {
        int curr = arr[i];
        int prev = i-1;

        while(prev>=0 && arr[prev]>curr)
        {
            arr[prev +1] = arr[prev];
            prev --;
        }
        arr[prev+1] = curr; // placing curr elementin its correct position
    }
}
void printarray(int arr[],int n)
{
    for(int i = 0 ;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n = 5;
    int arr[] = {2,3,5,1,7,8};
    insertionsort(arr,n);
    printarray(arr,n);
}