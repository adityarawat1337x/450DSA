#include<bits/stdc++.h>

using namespace std;

vector<int> cycleBfs(vector<int> adj[],int n){
    int vis[n]={0};
    for (int i = 1; i < n; i++){
        if(!vis[i]){
            queue<pair<int,int>> q;
            q.push({i,-1});
            vis[i] = 1;
            while(!q.empty()){
                auto x = q.front();
                for(auto i:adj[x.first]){
                    if(!vis[i]){
                        vis[i] = 1;
                        q.push({i,x.first});
                    }
                    else if(i!=x.second){
                        return {x.first, i};
                    }
                }
            q.pop();
            }
        }
    }
    return {-1, -1};
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
    auto ans = cycleBfs(adj,n+1);
    cout << ans[0] << ":" << ans[1];
}