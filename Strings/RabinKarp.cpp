#include <bits/stdc++.h>

using namespace std;

int main()
{
    string txt = "AABAACBAA", pat = "BAA";
    int hpat=0,htxt=0;
    int d = 26;
    int p = 5381;
    for (int i = 0; i < pat.size(); i++)
    {
        hpat *= d;
        hpat = hpat + (((pat[i] - 'A' + 1)) % p);
    }

    int l=0, r = 0;
    while (r < txt.size()){
        htxt *= d;
        htxt = htxt + ((txt[r] - 'A' + 1) % p);
        if(r-l+1==pat.size()){
            if(htxt==hpat)
                cout << "Match at " << l;
            htxt = htxt - (((txt[l] - 'A' + 1) * pow(d, r - l)));
            l++;
        }
        r++;
    }
    return 0;
}