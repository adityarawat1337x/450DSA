class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<pair<int,int>> v;
        vector<vector<int>> res;
        
        for(int i=0;i<b.size();i++){
            v.push_back({b[i][0],-b[i][2]});    
            v.push_back({b[i][1],b[i][2]});    
        }
        
        sort(v.begin(),v.end());
        int currHeight=0;
        multiset<int> ms;
        ms.insert(0);
        for(auto &[point,height]:v){

            if(height>0) ms.erase(ms.find(height));
            else ms.insert(-height);
            
            if(currHeight!=*ms.rbegin()){
                currHeight=*ms.rbegin();
                res.push_back({point,currHeight});
            }
        }
        return res;        
    }
};