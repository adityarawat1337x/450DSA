#include<bits/stdc++.h>
using namespace std;
 
int dp[100]={0};
 
int main(){
    int n;
    cin>>n;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    
    int a=0,b=1,c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    
    cout<<dp[n]<<" "<<c;
    return 0;
}