#include <bits/stdc++.h>

using namespace std;

int findPosition(int n) {
    if(n==0)
        return -1;

    if(n&(n-1))
        return -1;
    int ans=0;
    while(n){
        ans++;
        n=n>>1;
    }
    return ans;
}
