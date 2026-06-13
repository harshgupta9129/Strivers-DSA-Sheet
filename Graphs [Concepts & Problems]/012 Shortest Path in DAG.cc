#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<vector<pair<int, int>>> &adj, vector<int> &topo) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        int next = it.first;

        if (!vis[next]) {
            dfs(next, vis, adj, topo);
        }
    }

    // Push after visiting all neighbors
    topo.push_back(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges) {
    // Adjacency List: {neighbor, weight}
    vector<vector<pair<int, int>>> adj(n);

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        adj[u].push_back({v, wt});
    }

    // Step 1: Topological Sort using DFS
    vector<int> vis(n, 0);
    vector<int> topo;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, topo);
        }
    }

    reverse(topo.begin(), topo.end());

    // Step 2: Initialize distances
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    // Step 3: Relax edges in topological order
    for (int node : topo) {
        if (dist[node]==INT_MAX) continue;

        for (auto it : adj[node]) {
            int next = it.first;
            int wt = it.second;
            if (dist[node]+wt < dist[next]) dist[next]=dist[node]+wt;
        }
    }

    // Step 4: Mark unreachable nodes as -1
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
    }

    return dist;
}