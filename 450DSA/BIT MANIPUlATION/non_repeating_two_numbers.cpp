#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
       int XOR = 0;
       for(auto i:nums)
            XOR=XOR^i;
        int setbit = XOR & -(XOR);
        int set1=0;
       for(auto i:nums)
           {
               if(i&setbit){
                   set1=set1^i;
               }
           }
        vector<int> ans;
        ans.push_back(set1);
        ans.push_back(set1^XOR);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
