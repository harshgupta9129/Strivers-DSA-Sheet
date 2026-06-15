#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

        // Initialize distances with infinity
        vector<int> minDist(V, 1e8);
        minDist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i <= V - 1; i++) {

            bool updated = false;

            for (auto &it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                // Relax the edge if a shorter path is found
                if (minDist[u] != 1e8 &&
                    minDist[u] + wt < minDist[v]) {

                    minDist[v] = minDist[u] + wt;
                    updated = true;
                }
            }

            // No update means shortest paths are already finalized
            if (!updated) break;
        }

        // One extra pass to detect a negative weight cycle
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            // If relaxation is still possible, a negative cycle exists
            if (minDist[u] != 1e8 &&
                minDist[u] + wt < minDist[v]) {

                return {-1};
            }
        }

        return minDist;
    }
};