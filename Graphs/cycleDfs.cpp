#include<bits/stdc++.h>

using namespace std;

vector<int> cycleDfs(vector<int> adj[],int s,int p,int vis[]){
    vector<int> ans={-1,-1};
    for(auto i:adj[s]){
        if(!vis[i]){
            vis[i] = 1;
            ans = cycleDfs(adj,i, s, vis);
            if(ans[0]!=-1)
                break;
        }else if(i!=p){
            return {i, s};
        }
    }
    return ans;
}

int main(){
    int n,e;
    cin >> n >> e;
    vector<int> adj[n+1];
    for (int i = 0; i < e;i++){
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    int vis[n + 1] = {0};
    vector<int> ans={-1,-1};
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            vis[i] = 1;
            ans = cycleDfs(adj,i,-1,vis);
            if(ans[0]!=-1)
                break;
        }
    cout << ans[0] << ":" << ans[1];
}