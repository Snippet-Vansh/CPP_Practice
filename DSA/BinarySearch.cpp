#include <iostream>
using namespace std;

int main() {
    int arr[] = {2,4,6,8,10,12};
    int n = 6;

    int key = 8;
    int low = 0, high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == key){
            cout<<"Found at "<<mid;
            return 0;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout<<"Not Found";
}