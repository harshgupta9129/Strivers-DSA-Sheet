#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUParent(parent[node]); // Path Compression
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int getSize(int node) {
        return size[findUParent(node)];
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        // Build connected components
        for (auto &edge : edges) {
            ds.unionBySize(edge[0], edge[1]);
        }

        vector<long long> compSizes;

        // Collect sizes of all components
        for (int i = 0; i < n; i++) {
            if (ds.findUParent(i) == i) {
                compSizes.push_back(ds.getSize(i));
            }
        }

        long long ans = 0;
        long long remaining = n;

        // Count unreachable pairs
        for (long long sz : compSizes) {
            remaining -= sz;
            ans += sz * remaining;
        }

        return ans;
    }
};