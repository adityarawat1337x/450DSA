#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,e;
    cin >> n >> e;
    vector<pair<int,int>> adj[n+1];
    for (int i = 0; i < e;i++){
        int v, u,wt;
        cin >> v >> u>> wt;
        adj[v].push_back({u,wt});
        adj[u].push_back({v,wt});
    }
    int source;
    cin >> source;

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int> >> pq;
    vector<int> dist(n + 1, INT_MAX);
    dist[source] = 0;
    pq.push({dist[source], source});

    while(!pq.empty()){
        auto dis = pq.top().first;
        auto parent = pq.top().second;
        pq.pop();

        for(auto i:adj[parent]){
            auto node = i.first;
            auto newDis = i.second;
            if(dist[node]>dist[parent]+newDis){
                dist[node] = dist[parent] + newDis;
                pq.push({dist[node], node});
            }   
        }
    }
    
    cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << dist[i] << " ";
	cout << "\n";

}