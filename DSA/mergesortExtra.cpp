#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &a,int st,int mid,int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    while(i<=mid && j<=end)
    {
        if(a[i]= a[j])
        {
            temp.push_back(a[i]);
            i++;
        }else{
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(a[i]);
        i++;
    }
     while(j<=end)
    {
        temp.push_back(a[j]);
        j++;
    }
    for(int idx = 0;idx<temp.size(); idx++)
    {
        a[idx+st] = temp[idx];
    }
}
void mergesort(vector<int> &a,int st,int mid,int end)
{
    if(st<end)
    {
        int mid = st + (end -st)/2;
     
        mergesort(a,st,mid,mid);
        mergesort(a,mid+1,end,end);
    }
} 
int main()
{
    vector<int> a = {3,5,1,6,8};
    mergesort(a,0,(a.size()-1)/2,a.size()-1);
    //mergesort(a,0,a.size()-1);
    for(int val : a)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;

}