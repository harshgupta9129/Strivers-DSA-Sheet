// https://leetcode.com/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        // Store minimum effort required to reach each cell
        vector<vector<int>> miniEffort(m, vector<int>(n, INT_MAX));

        // Set stores {effort, row, col} in sorted order
        set<vector<int>> st;

        miniEffort[0][0] = 0;
        st.insert({0, 0, 0});

        while (!st.empty()) {

            // Get cell with minimum effort
            auto it = *st.begin();

            int effort = it[0];
            int row = it[1];
            int col = it[2];

            st.erase(it);

            // Explore all 4 directions
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                // Check if the new cell is inside the grid
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    // Effort of current path to reach neighbor
                    int newEffort = max(
                        effort,
                        abs(heights[nr][nc] - heights[row][col])
                    );

                    // Update if a better path is found
                    if (newEffort < miniEffort[nr][nc]) {

                        // Remove old entry from set if present
                        if (miniEffort[nr][nc] != INT_MAX) {
                            st.erase({miniEffort[nr][nc], nr, nc});
                        }

                        miniEffort[nr][nc] = newEffort;
                        st.insert({newEffort, nr, nc});
                    }
                }
            }
        }

        // Minimum effort needed to reach bottom-right cell
        return miniEffort[m - 1][n - 1];
    }
};