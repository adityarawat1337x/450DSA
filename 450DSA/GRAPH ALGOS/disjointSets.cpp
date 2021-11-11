#include <bits/stdc++.h>

using namespace std;

int parent[100000], ranks[100000];

void makeSet(int n)
{
    for (int i = 0; i < n; i++){
        parent[i] = i;
        ranks[i] = 0;
    }
}


int findParent(int node){
    if(node==parent[node])
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionSet(int u,int v){
    u = findParent(u);
    v = findParent(v);
    if (ranks[u] == ranks[v])
    {
        parent[v] = u;
        ranks[u]++;
    }
    else if(ranks[v]>ranks[u]){
        parent[u] = v;
    }else
        parent[v] = u;
}


int main()
{
    int n, e;
    cin >> n >> e;
    makeSet(n);
    while(e--){
        int a, b;
        cin >> a >> b;
        unionSet(a, b);
    }
    cout << "\ncheck if same component:";
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(findParent(a)==findParent(b))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
