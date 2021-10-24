#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int setBits(int n) {
        int count=0;
        while(n){
            count++;
            n=n&(n-1);
        }
    return count;

    }
};
