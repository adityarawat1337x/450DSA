#include<bits/stdc++.h>
using namespace std;
 
unordered_map<int,int> dp;

void solve(int n){
    if(n==0 || n==1)
        dp[n]=n;
    else{
        if(!dp[n-1])
            solve(n-1);
        dp[n]=dp[n-1]+dp[n-2];
    }
}
 
int main(){
    int n;
    cin>>n;
    solve(n);
    cout<<dp[n];
    return 0;
}