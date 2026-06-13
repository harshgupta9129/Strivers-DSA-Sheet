#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {

    // Build undirected weighted graph
    vector<vector<pair<int, int>>> adj(vertices);

    for (vector<int> p : vec) {
        adj[p[0]].push_back({p[1], p[2]});
        adj[p[1]].push_back({p[0], p[2]});
    }

    // Store {distance, node} in sorted order
    set<pair<int, int>> st;

    // Store shortest distance from source
    vector<int> dist(vertices, INT_MAX);

    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty()) {

        // Get node with minimum distance
        auto it = *(st.begin());
        st.erase(it);

        int dis = it.first;
        int node = it.second;

        // Skip outdated entries
        if (dis > dist[node]) continue;

        // Relax all adjacent edges
        for (auto p : adj[node]) {

            int next = p.first;
            int d = p.second;

            if (dis + d < dist[next]) {
                
                // If Already Exits Remove it
                if (dist[next]!=INT_MAX) st.erase({dist[next], next});
                dist[next] = dis + d;
                st.insert({dist[next], next});
            }
        }
    }

    // Return shortest distance to every vertex
    return dist;
}