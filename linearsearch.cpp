#include <iostream>
using namespace std;

int main() {
    int arr[] = {5,8,2,10,15};
    int n = 5;
    int key = 10;

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"Found at index "<<i;
            return 0;
        }
    }

    cout<<"Not Found";
}