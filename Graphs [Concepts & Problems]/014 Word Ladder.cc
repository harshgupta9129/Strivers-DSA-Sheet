#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> words;
        for (string s : wordList) words.insert(s);
        queue <pair <string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);

        // BFS Traversal Technique
        while (q.size()) {
            string s = q.front().first;
            int level = q.front().second;
            q.pop();
            if (s==endWord) return level;
            for (int i=0; i<s.length(); i++) {
                string temp = s;
                for (char c = 'a'; c<='z'; c++) {
                    temp[i]=c;
                    if (words.count(temp)) {
                        q.push({temp, level+1});
                        words.erase(temp);
                    }  
                }
            }
        }
        return 0;
    }
};