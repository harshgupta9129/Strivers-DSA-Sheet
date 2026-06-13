// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

        // Build undirected weighted graph
        vector<vector<pair<int, int>>> adj(n + 1);
        for (vector<int> p : edges) {
            adj[p[0]].push_back({p[1], p[2]});
            adj[p[1]].push_back({p[0], p[2]});
        }

        // Set stores {distance, node} in sorted order
        set<pair<int, int>> st;
        st.insert({0, 1});

        // Store shortest distance from source node 1
        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;

        // Store parent of each node for path reconstruction
        vector<int> pt(n + 1);
        for (int i = 0; i <= n; i++) {
            pt[i] = i;
        }

        while (!st.empty()) {

            // Get node with minimum distance
            auto it = *st.begin();
            int dis = it.first;
            int node = it.second;
            st.erase({dis, node});

            // Skip outdated entries
            if (dis > dist[node]) continue;

            // Relax all adjacent edges
            for (auto p : adj[node]) {

                int next = p.first;
                int wt = p.second;

                if (dis + wt < dist[next]) {

                    // Remove old distance if present
                    if (dist[next] != INT_MAX) {
                        st.erase({dist[next], next});
                    }

                    dist[next] = dis + wt;
                    st.insert({dist[next], next});

                    // Update parent for shortest path
                    pt[next] = node;
                }
            }
        }

        // No path exists from 1 to n
        if (dist[n] == INT_MAX) return {-1};

        // Reconstruct shortest path
        vector<int> ans;
        int i = n;

        ans.push_back(n);

        while (i != 1) {
            ans.push_back(pt[i]);
            i = pt[i];
        }

        // Add total shortest distance
        ans.push_back(dist[n]);

        // Reverse to get correct order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};