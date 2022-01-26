// power function in logn time

#include <bits/stdc++.h>

using namespace std;


int power(int a,int b){
    if(b==0)
        return 1.0;

    if(b&1)
        return a*power(a*a,b>>1);
    return power(a*a,b>>1);
}

int main()
{
    int a,b;
    cin>>a>>b;
    float ans=0;

    if(b<0){
        b = -b;
        ans = power(a,b);
        ans = 1.0/(float)ans;
    }
    else
        ans = power(a,b);

    cout<<ans;
    return 0;
}
