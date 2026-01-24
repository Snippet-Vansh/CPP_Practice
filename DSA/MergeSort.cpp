#include <iostream>
using namespace std;

void merge(int mid, int b[], int low, int a[], int high)
{
    int i, j, k;
    i = low;
    k = low;
    j = mid + 1;
    while (i < mid && j < high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid) // loop for combining remaining element of a[] in c[]
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high) // loop for combining remaining element of b[] in c[]
    {
        b[k] = a[j];
        k++;
        j++;
    }
}
void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    cout << endl;
}
void mergesort(int a,int low ,int high)
{
    int mid;
    int high;
    if(low<high)
    {
        mid =  (low + high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        mergesort(a,mid,high);
    }
} 
int main()
{
    int a[] = {4, 6, 2, 13, 9, 7};
    int n = 6;
    printarray(a,n);
    mergesort(a,0,n-1);
    printarray(a,n);
}