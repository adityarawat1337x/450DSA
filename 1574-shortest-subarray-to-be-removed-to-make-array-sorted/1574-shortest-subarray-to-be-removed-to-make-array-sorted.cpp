class Solution {
public:
    int check(vector<int> front,vector<int> back){
        int idx=-1,maxS=0;
        for(int i=0;i<back.size();i++){
            int up = upper_bound(front.begin(),front.end(),back[i])-front.begin();
            if(up+i+1>maxS){
                cout<<idx<<" "<<up+i+1<<", ";
                maxS=up+i+1;
                idx=up;
            }
        }
     //   for(auto i:front) cout<<i<<" ";
       // cout<<endl;
       // for(auto i:back) cout<<i<<" ";
       // cout<<endl<<idx;
        while(front.size()>idx) front.pop_back();
        while(front.size() and back.size() and front.back()>back.back()) back.pop_back(); 
      
        return front.size()+back.size();
    }

    int findLengthOfShortestSubarray(vector<int>& arr) {
 
        vector<int> front,back;
        int j=0;
        for(j=0;j<arr.size();j++){
            if(front.size()==0 or front.back()<=arr[j]) front.push_back(arr[j]);
            else break;
        }
        
        if(front.size()==arr.size()) return 0;
        
        for(int i=arr.size()-1;i>=j;i--){
            if(back.size()==0 or back.back()>=arr[i]) back.push_back(arr[i]);
            else break;
        }
        
        //reverse(back.begin(),back.end());
        return arr.size()-max({(int)check(front,back),(int)front.size(),(int)back.size()});
    }
};