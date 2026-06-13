#include <bits/stdc++.h>
using namespace std;

bool detectedbydfs (int node, int prt, vector <int> &isvisited, vector <vector <int>> &adj) {
    isvisited[node]=1;
    for (int x : adj[node]) {
        if (!isvisited[x]) {
            if (detectedbydfs(x, node, isvisited, adj)) return true;
        }
        else {
            if (x!=prt) return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector <vector <int>> adj(n+1);
    for (vector <int> p : edges) {
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
    }
    vector <int> isvisited(n+1, 0);
    for (int i=1; i<=n; i++) {
        if (!isvisited[i]) {
            if (detectedbydfs(i, -1, isvisited, adj)) return "Yes";
        }
    }
    return "No";
}
