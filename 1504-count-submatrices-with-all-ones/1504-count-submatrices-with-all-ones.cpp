class Solution {
public:
    int count(vector<int> &m){
        stack<int> s;
        int res=0;
        vector<int> sum(m.size());
        for(int i=0;i<m.size();i++){
            while(!s.empty() and m[s.top()]>=m[i]) s.pop();
            
            if(s.empty()){
                sum[i]=m[i]*(i+1);
            }else{
                sum[i]=(i-s.top())*m[i];
                sum[i]+=sum[s.top()];
            }
            
            s.push(i);
        }
        for(auto &i:sum) res+=i;
        
        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        vector<int> m(mat[0].size());
        int res=0;
        
        for(int r=0;r<mat.size();r++){
            for(int c=0;c<mat[0].size();c++)
                m[c]=(mat[r][c]==0)?0:m[c]+1;
            res+=count(m);
        }
        
        return res;
    }
};