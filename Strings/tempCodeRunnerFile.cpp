
int main()
{
    string txt = "abxabcabcaby", pat = "abcdeabfabc";
    vector<int> lps(pat.size());

    for (int i = 0; i < pat.size();i++)
        for (int j = i+1; j < pat.size();j++)
            if(pat[i]==pat[j])
                lps[j] = lps[i++] + 1;
    
    for(auto i:lps)
        cout << i << " ";
    return 0;
}
