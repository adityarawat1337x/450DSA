#include <bits/stdc++.h>

using namespace std;

vector<int> createLps(string s){
    int n = s.size();
    vector<int> lps(n,0);
    for (int i = 1; i < n;i++){
        int j = lps[i - 1];
        while(j>0 and s[i]!=s[j])
            j=lps[j - 1];
        if (s[i] == s[j])
            j++;

        lps[i] = j;
    }

    return lps;
}

vector<int> findIndex(string s,string p,vector<int> lps){
    vector<int> index;
    for (int i = 0, j = 0; i < s.size();)
    {
        if(j<p.size() && s[i]==p[j]){
            i++;
            j++;
        }else
            if(j!=0)
                j = lps[j - 1];
            else
                i++;
        if(j==p.size()){
            index.push_back(i-j);
            j = lps[j - 1];
        }
    }

    return index;
}
int main()
{
    string s = "abcbabcbabcbabca", p = "bcba";
    vector<int> lps = createLps(p);
    for (auto i : lps)
        cout << i << " ";
    vector<int> matched = findIndex(s, p, lps);
    cout<<"\nfound at : ";
     for (auto i : matched)
            cout<<i<< " ";

    return 0;
}
