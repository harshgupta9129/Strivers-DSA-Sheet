#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        vector <int> minMulti (1000, INT_MAX);
        queue <pair<int,int>> q;
        q.push({0, start});
        minMulti[start]=0;
        while (!q.empty()) {
            auto [steps, node] = q.front();
            q.pop();
            if (steps==INT_MAX) continue;
            if (node==end) return steps;
            for (int x : arr) {
                int next = (x*node)%1000;
                if (steps+1 < minMulti[next]) {
                    minMulti[next]=steps+1;
                    q.push({minMulti[next], next});
                }
            }
        }
        return (minMulti[end]!=INT_MAX ? minMulti[end] : -1);
    }
};