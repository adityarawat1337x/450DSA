// Find missing and duplicate values in 1 -> n  array

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[7] = {1,2,4,5,5,7,2};
    int n=7;
    for(int i=0;i<n;){
        if(arr[i]!=arr[arr[i]-1])
            swap(arr[i],arr[arr[i]-1]);
        else i++;
    }

    for(int i=0;i<n;i++){
        if(arr[i]!=i+1)
            cout<<"Missing: "<<i+1<<" Duplicate: "<<arr[i]<<"\n";
    }

    return 0;
}
