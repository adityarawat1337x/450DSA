#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],int arr[],int x){
    cout << x << " ";
    arr[x] = 1;
    for(auto i:adj[x]){
        if(!arr[i]){
            dfs(adj, arr, i);
        }
    }
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
    int arr[n]={0};
    for (int i = 1; i < n;i++){
        if(!arr[i]){
            dfs(adj,arr,i);
        }
    }
}