#include<bits/stdc++.h>

using namespace std;
void helper2(string mail, unordered_map<string, vector<int>> graph, vector<vector<string>> nd, unordered_map<string, int> &vismail, vector<int> &vis, set<string> &emails);
void helper(int index, unordered_map<string, vector<int>> graph, vector<vector<string>> nd, unordered_map<string, int> &vismail, vector<int> &vis, set<string> &emails)
{
    if (vis[index])
        return;
    vis[index] = 1;
    for (int i = 0; i < nd[index].size(); i++)
    {
        if (vismail[nd[index][i]])
            continue;
        vismail[nd[index][i]] = 1;
        emails.insert(nd[index][i]);
        helper2(nd[index][i], graph, nd, vismail, vis, emails);
    }
    }
    
        
    void helper2(string mail,unordered_map<string,vector<int>> graph,vector<vector<string>> nd,unordered_map<string,int>& vismail, vector<int>& vis,set<string>& emails){
        if(vismail[mail])
            return;
        vismail[mail]=1;
        for(int i=0;i<graph[mail].size();i++){
            if(vis[graph[mail][i]])
                continue;
            vis[graph[mail][i]]=1;
            helper(graph[mail][i],graph,nd,vismail,vis,emails);
        }
    }
    
    int main(){
        vector<vector<string>> accounts={{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
        vector<vector<string>> ans;
        unordered_map<string,vector<int>> graph;
        vector<vector<string>> nd(accounts.size(),vector<string>());

        unordered_map<string,int> vismail;
        
        for(int i=0;i<accounts.size();i++)
            for(int j=1;j<accounts[i].size();j++){
                graph[accounts[i][j]].push_back(i);
                nd[i].push_back(accounts[i][j]);
                vismail[accounts[i][j]]=0;
                // cout<<accounts[i][j]<<" "<<i<<" ";
                // cout<<accounts[i][j]<<" "<<i<<" ";
            }
                 
        vector<int> vis(accounts.size(),0);

        for(int i=0;i<accounts.size();i++){
            set<string> emails;
            helper(i,graph,nd,vismail,vis,emails);
            for(auto i: emails)
                cout<<i<<" ";
        }
    return 0;
    }




//unordered_map<string,>emails
