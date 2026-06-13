#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &isvisited, vector <int> &pathvisited, vector <int> &check, vector <vector <int>> &adj) {
    isvisited[node]=1;
    pathvisited[node]=1;
    for (int next : adj[node]) {
        if (!isvisited[next]) {
            if (dfs(next, isvisited, pathvisited, check, adj)) return true;
        }
        if (pathvisited[next]) return true;
    }
    pathvisited[node]=0;
    check[node]=1;
    return false;
}

vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    vector<vector<int>> adj(n);
    for (auto &p : edges) {
        adj[p[0]].push_back(p[1]);
    }
    vector <int> isvisited(n, 0);
    vector <int> pathvisited(n, 0);
    vector <int> check(n, 0);
    for (int i=0; i<n; i++) {
        if (!isvisited[i]) dfs(i, isvisited, pathvisited, check, adj);
    }
    vector <int> ans;
    for (int i=0; i<n; i++) {
        if (check[i]) ans.push_back(i);
    }
    return ans;
}