#include <bits/stdc++.h>
using namespace std;


void copySetBits(unsigned &x, unsigned y,
                 unsigned l, unsigned r)
{
    if (l < 1 || r > 32)                   //                      l  r
        return ;                          //                   101010110101   = y
    int maskLength = (1ll<<(r-l+1)) - 1;  // this is equal to      1111   masklength
    int mask = ((maskLength)<<(l-1)) & y ; // this is equal to 000011110000 & 101010110101
    x = x | mask;                           // now we will do   000010110000
}                                          //                or 101000101010
                                          //                    101010111010 ans

// Driver code
int main()
{
   unsigned x = 10, y = 13, l = 2, r = 3;
   copySetBits(x, y, l, r);
   cout << "Modified x is " << x;
   return 0;
}
