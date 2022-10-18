class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        int ctr=0;
        string s = countAndSay(n-1);
        cout<<s<<" ";
        string ans="";
        for(int i=0;i<s.size();i++){
            ctr=0;
            for(int j=i;j<s.size();j++){
                if(s[j]!=s[i]) break;
                i=j;
                ctr++;
            }   
            ans+=to_string(ctr)+s[i];
        }
        return ans;
    }
};