#include <bits/stdc++.h>

using namespace std;


class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){

    int XOR = a^b;
    int ans=0;

    while(XOR){
        ans++;
        XOR=XOR&(XOR-1);
    }
    return ans;

}
};
