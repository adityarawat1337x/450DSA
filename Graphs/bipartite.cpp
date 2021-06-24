#include<bits/stdc++.h>

using namespace std;

bool bfs(vector<int> adj[],int n){
    vector<int> col(n,-1);
    for (int i = 1; i < n;i++){
        if(col[i] == -1){
            queue<int> q;
            q.push(i);
            col[i] = 1;
            while(!q.empty()){
                int x = q.front();
                for(auto j:adj[x]){
                    if(col[j] == -1){
                        q.push(j);
                        col[j] = 1-col[x];
                        }
                    else if(col[j]==col[x]){
                        return false;
                    }
                }
                q.pop();
            }
        }
    }
    return true;
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
    auto ans = bfs(adj,n+1);
    if(!ans)
        cout << "Not ";
    cout << "Bipartite";
}