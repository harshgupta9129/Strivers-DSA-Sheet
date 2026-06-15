#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector <int> rank, parent;
    DisjointSet (int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i=0; i<n; i++) parent[i]=i;
    }

    int findUpParent (int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUpParent(parent[node]);
    }

    void unionByRank (int u, int v) {
        int ulp_u = findUpParent(u);
        int ulp_v = findUpParent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        // Step 1
        // sort edges on basis of wt
        sort(edges.begin(), edges.end(), [](vector <int> &a, vector <int> &b) {
            return a[2]<b[2];
        });

        int mstSum = 0;
        DisjointSet ds(V);
        for (auto it : edges) {

            // If Both Node Have Same Ultimate Parent Then The Are Already Reachable
            if (ds.findUpParent(it[0]) == ds.findUpParent(it[1])) continue;

            // Connect By unionByRank
            ds.unionByRank(it[0], it[1]);
            mstSum+=it[2];
        }
        return mstSum;
    }
};