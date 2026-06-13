// https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
// https://www.naukri.com/code360/problems/shortest-path-in-a-binary-maze_893065?interviewProblemRedirection=true&search=Binary%20Maze&attempt_status=COMPLETED&leftPanelTabValue=PROBLEM&count=25&sort_entity=order&sort_order=ASC&customSource=studio_nav&page=1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        int m = mat.size();
        int n = mat[0].size();
        if (!mat[src[0]][src[1]] || !mat[dest[0]][dest[1]]) return -1;
        vector <vector <int>> dist(m, vector <int> (n, INT_MAX));
        set <vector <int>> st;
        st.insert({0, src[0], src[1]});
        dist[src[0]][src[1]]=0;
        while (!st.empty()) {
            auto it = *(st.begin());
            int dis = it[0];
            int row = it[1];
            int col = it[2];
            st.erase(it);
            if (dis==INT_MAX) continue;
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            for (int i=0; i<4; i++) {
                int nr = row+dr[i];
                int nc = col+dc[i];
                if (nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc] && dis+1<dist[nr][nc]) {
                    if (dist[nr][nc]!=INT_MAX) st.erase({dist[nr][nc], nr, nc});
                    dist[nr][nc]=dis+1;
                    st.insert({dist[nr][nc], nr, nc});
                }
            }
        }
        return (dist[dest[0]][dest[1]]==INT_MAX ? -1 : dist[dest[0]][dest[1]]);
    }
};

#include<bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &mat, pair<int, int> src, pair<int, int> dest) {
    int m = mat.size();
    int n = mat[0].size();
    if (!mat[src.first][src.second] || !mat[dest.first][dest.second]) return -1;
    vector <vector <int>> dist(m, vector <int> (n, INT_MAX));
    set <vector <int>> st;
    st.insert({0, src.first, src.second});
    dist[src.first][src.second]=0;
    while (!st.empty()) {
        auto it = *(st.begin());
        int dis = it[0];
        int row = it[1];
        int col = it[2];
        st.erase(it);
        if (dis==INT_MAX) continue;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i=0; i<4; i++) {
            int nr = row+dr[i];
            int nc = col+dc[i];
            if (nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc] && dis+1<dist[nr][nc]) {
                if (dist[nr][nc]!=INT_MAX) st.erase({dist[nr][nc], nr, nc});
                dist[nr][nc]=dis+1;
                st.insert({dist[nr][nc], nr, nc});
            }
        }
    }
    return (dist[dest.first][dest.second]==INT_MAX ? -1 : dist[dest.first][dest.second]);
}