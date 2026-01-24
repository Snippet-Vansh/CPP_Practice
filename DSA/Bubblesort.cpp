#include<iostream>
using namespace std;

void printarray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}
void bubblesort(int arr[],int n)
{
  int  isSorted = 0;
    for(int i=0; i<n-1;i++) // for num of passes
    {
        cout <<"working on pass num "<<i<<endl;
        isSorted = 1;
       for(int j=0;j<n-1-i;j++) //for comparision in each pass
       {
        if(arr[j]>arr[j+1])
        {
          int  temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
       }
    }
}
int main()
{
    int arr[] = {4,6,3,2,9};
    int n = 5;
    cout<<"original array:";
    printarray(arr,n); 
    bubblesort(arr,n);
    cout<<"sorted array:";
    printarray(arr,n);

}