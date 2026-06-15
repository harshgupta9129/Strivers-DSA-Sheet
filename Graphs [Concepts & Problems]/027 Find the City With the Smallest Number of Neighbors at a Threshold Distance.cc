// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector <vector <int>> dist(n, vector <int> (n, INT_MAX));
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for (int via = 0; via<n; via++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (dist[i][via]==INT_MAX || dist[via][j]==INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }
        int ans = 0;
        int miniNumberofCity = n;
        for (int i=0; i<n; i++) {
            int temp = 0;
            for (int j=0; j<n; j++) {
                if (i==j) continue;
                if (dist[i][j]<=distanceThreshold) temp++;
            }
            if (temp<=miniNumberofCity) {
                miniNumberofCity = temp;
                ans = i;
            }
        }
        return ans;
    }
};