#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUpParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUpParent(parent[node]);
    }

    bool unionByRank(int u, int v) {
        int ulp_u = findUpParent(u);
        int ulp_v = findUpParent(v);

        if (ulp_u == ulp_v) return false;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

        return true;
    }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q) {
    DisjointSet ds(n * m);

    vector<vector<int>> land(n, vector<int>(m, 0));
    vector<int> ans;

    int islands = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (auto &it : q) {
        int row = it[0];
        int col = it[1];

        // Duplicate query
        if (land[row][col]) {
            ans.push_back(islands);
            continue;
        }

        land[row][col] = 1;
        islands++;

        int node = row * m + col;

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && land[nr][nc]) {

                int adjNode = nr * m + nc;

                // If two different islands merge
                if (ds.unionByRank(node, adjNode)) {
                    islands--;
                }
            }
        }

        ans.push_back(islands);
    }

    return ans;
}