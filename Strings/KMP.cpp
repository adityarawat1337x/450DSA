#include <bits/stdc++.h>

using namespace std;

void match(string txt,string pat,vector<int> lps){
    for (int j=0,i = 0; i < txt.size();){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }else if(j==0)
            i++;
        else
            j = lps[j - 1];

        if(j==lps.size()){
            cout << "pattern found at "<<i-j<<endl;
            j = lps[j - 1];
            }
    }
}

void lpscalc(string pat,vector<int>& lps){

    for (int i = 0, j = 1; i < pat.size() && j<pat.size();)
        if(pat[i]==pat[j]){
            i++;
            lps[j] = i;
            j++;
        }else if(i!=0){
            i = lps[i - 1];
        }else{
            j++;
        }

    for(auto i:lps)
        cout << i << " ";
}

int main()
{
    string txt = "hello", pat = "AABA";
    vector<int> lps(pat.size());

    lpscalc(pat, lps);
    match(txt,pat, lps);
    return 0;
}
