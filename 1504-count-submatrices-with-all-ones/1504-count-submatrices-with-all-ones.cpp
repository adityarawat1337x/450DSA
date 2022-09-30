class Solution {
public:
    int count(vector<int> &m){
        int res=0,prev=0;
        for(int i=0;i<m.size();i++){
            prev=(m[i]==0)?0:prev+1;
            res+=prev;
        }
        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int res=0;
        for(int r1=0;r1<mat.size();r1++){
            vector<int> m(mat[0].size(),1);
            for(int r2=r1;r2<mat.size();r2++){
                for(int c=0;c<mat[0].size();c++){
                    m[c]&=mat[r2][c];
                }
                res+=count(m);
            }
        }
        
        return res;
    }
};