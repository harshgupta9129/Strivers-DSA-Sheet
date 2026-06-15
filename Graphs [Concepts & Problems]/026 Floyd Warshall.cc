// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        int INF = 1e8;

        // Floyd-Warshall Algorithm:
        // Finds the shortest distance between every pair of vertices.
        // For each vertex 'via', check whether using it as an intermediate
        // node provides a shorter path from i to j.

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    // A path through 'via' is possible only if both
                    // i -> via and via -> j paths exist.
                    if (dist[i][via] == INF || dist[via][j] == INF) continue;

                    // Relax the distance using 'via' as an intermediate node.
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
};