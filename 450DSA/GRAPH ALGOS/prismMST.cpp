#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,e;
    cin >> N >> e;
    int a, b, c;
    vector<pair<int, int>> graph[N];
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        graph[b].push_back(make_pair(a, c));
        graph[a].push_back(make_pair(b, c));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(N, INT_MAX);
    vector<int> mst(N, 0);
    vector<int> parent(N, -1);

    mst[0] = 1;
    key[0] = 0;
    pq.push({0, 0});

    for (int i = 0; i < N-1; i++)
    {
        int par = pq.top().first;
        pq.pop();
        mst[par] = 1;

        for(auto it:graph[par]){
            int child = it.first;
            int weight = it.second;
            if(mst[child]==0 && weight<key[child]){
                key[child] = weight;
                parent[child] = par;
                pq.push({child, weight});
            }
        }
    }

    for (int i = 1; i < parent.size(); i++)
    {
        cout << "\nParent of " << i<< " -> "<<  parent[i] ;
    }

    return 0;
}
