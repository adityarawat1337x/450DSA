#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],int n){
    int arr[n]={0};
    for (int i = 1; i < n;i++){
            if(!arr[i]){
                queue<int> q;
                q.push(i);
                arr[i] = 1;
                while(!q.empty()){
                    int x = q.front();
                    cout << x <<" ";
                    for(auto j:adj[x]){
                        if(!arr[j]){
                            q.push(j);
                            arr[j] = 1;
                            }
                    }
                    q.pop();
                }
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
    bfs(adj,n+1);
}