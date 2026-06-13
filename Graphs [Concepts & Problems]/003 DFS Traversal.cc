#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector <vector <int>> &adj, vector <int> &visited, vector <vector <int>> &ans) {
    ans[ans.size()-1].push_back(i);
    visited[i]=1;
    for (int x : adj[i]) {
        if (!visited[x]) dfs(x, adj, visited, ans);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector <vector <int>> adj (V);
    for (vector <int> p : edges) {
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
    }
    vector <int> visited(V, 0);
    vector <vector <int>> ans;
    for (int i=0; i<V; i++) {
        if (!visited[i]) {
            ans.push_back({});
            dfs(i, adj, visited, ans);
        }
    }
    return ans;
}