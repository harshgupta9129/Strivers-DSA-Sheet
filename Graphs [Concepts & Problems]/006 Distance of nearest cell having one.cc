#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue <vector <int>> q;
        vector <vector <int>> isvisited(m, vector <int> (n, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j]==0) {
                    q.push({i, j, 0});
                    isvisited[i][j]=1;
                }
            }
        }
        vector <vector <int>> ans(m, vector <int> (n, 0));
        while (q.size()) {
            int row = q.front()[0];
            int col = q.front()[1];
            int dis = q.front()[2];
            ans[row][col]=dis;
            q.pop();
            row--;
            if (row>=0 && !isvisited[row][col]) {
                q.push({row, col, dis+1});
                isvisited[row][col]=1;
            }
            row+=2;
            if (row<m && !isvisited[row][col]) {
                q.push({row, col, dis+1});
                isvisited[row][col]=1;
            }
            row--;
            col--;
            if (col>=0 && !isvisited[row][col]) {
                q.push({row, col, dis+1});
                isvisited[row][col]=1;
            }
            col+=2;
            if (col<n && !isvisited[row][col]) {
                q.push({row, col, dis+1});
                isvisited[row][col]=1;
            }
        }
        return ans;
    }
};