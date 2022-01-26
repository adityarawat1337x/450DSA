// multiply 2 numbers without using x
// a*b = (a/2)*b*2          a = even
// a*b = (a/2)*b*2 + b      a = odd


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int ans = 0,sign=1;
    if(a<0){
        a=-a;
        sign=-sign;
    }

    if(b<0){
        b=-b;
        sign=-sign;
    }

    while(b>1){
        if(b&1){
            ans+=a;
        }
        a=a<<1;
        b=b>>1;
    }

    ans+=a;
    ans=sign>0?ans:-ans;
    cout<<ans;
    return 0;
}
