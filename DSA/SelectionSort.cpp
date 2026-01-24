#include<iostream>
using namespace std;

void selectionSort(int arr[],int n)
{
    for(int i = 0; i<n-1; i++)
    {
        int smallestindex = i; //unsorted part starting
        for(int j = i+1; j<n;j++)
        {
            if(arr[j]<arr[smallestindex])
            {
                smallestindex = j;
                // int temp = arr[i];
                // arr[i]  = arr[si];
                // arr[si] = temp;
            }
        }
        // swap(arr[i],arr[smallestindex]);
         int temp = arr[i];
         arr[i] = arr[smallestindex];
         arr[smallestindex] = temp;
    }
}
void printarray(int arr[],int n)
{
    for(int i= 0;i<n-1;i++)
    {
       cout<<arr[i]<<" "; 
    }
    cout<<endl;
}
int main()
{
    int n = 5;
    int arr[] = {4,1,3,6,8};
    selectionSort(arr,n);
    cout<<"sorted array :";
    printarray(arr,n);
}