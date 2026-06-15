#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int row, int col, vector <vector <int>> &vis, vector<vector<char>>& grid) {
        queue <tuple<int,int,int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        q.push({row, col, -1, -1});
        vis[row][col]=1;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [row, col, pr, pc] = q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                int nr = row+dr[i];
                int nc = col+dc[i];
                if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==grid[row][col]) {
                    if (!vis[nr][nc]) {
                        vis[nr][nc]=1;
                        q.push({nr, nc, row, col});
                    }
                    else if (nr!=pr || nc!=pc) return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector <vector <int>> vis(m, vector <int> (n, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!vis[i][j]) {
                    if (bfs(i, j, vis, grid)) return true;
                }
            }
        }
        return false;
    }
};