#include <queue>
#include <vector>
#include <utility>
using namespace std;

bool dfs (int node, vector <int> &pathvisited, vector <int> &isvisited, vector <vector <int>> &adj) {
    pathvisited[node]=1;
    isvisited[node]=1;
    for (int x : adj[node]) {
        if (!isvisited[x]) {
            if (dfs(x, pathvisited, isvisited, adj)) return true; 
        }
        else if (pathvisited[x]) return true;
    }
    pathvisited[node]=0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n + 1);
    for (const pair<int, int>& p : edges) {
        adj[p.first].push_back(p.second);
    }
    vector <int> isvisited(n+1, 0);
    vector <int> pathvisited(n+1, 0);
    for (int i=1; i<=n; i++) {
        if (!isvisited[i]) {
            if (dfs(i, pathvisited, isvisited, adj)) return true;
        } 
    }
    return 0;
}