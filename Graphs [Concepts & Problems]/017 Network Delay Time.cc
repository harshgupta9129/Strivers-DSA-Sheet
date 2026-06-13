#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Build directed weighted graph
        vector<vector<pair<int, int>>> adj(n + 1);
        for (vector<int> p : times) {
            adj[p[0]].push_back({p[1], p[2]});
        }

        // Store shortest distance from source node k
        vector<int> dist(n + 1, INT_MAX);

        // Min-heap: {distance, node}
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated entries in the heap
            if (dis > dist[node]) continue;

            // Relax all outgoing edges
            for (auto it : adj[node]) {

                int next = it.first;
                int d = it.second;

                if (dis + d < dist[next]) {
                    dist[next] = dis + d;
                    pq.push({dist[next], next});
                }
            }
        }

        // Check if every node is reachable
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
        }

        // Maximum shortest distance is the answer
        return *max_element(dist.begin() + 1, dist.end());
    }
};