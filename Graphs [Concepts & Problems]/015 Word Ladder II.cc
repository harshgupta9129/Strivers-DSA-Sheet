#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return {};
        vector<vector<string>> ans;

        // Queue stores complete paths instead of just words
        queue<vector<string>> q;
        q.push({beginWord});

        // Words used at the current BFS level
        // They will be removed only after the entire level is processed
        vector<string> wordOnLevel;
        wordOnLevel.push_back(beginWord);
        int level = 1;
        while (!q.empty()) {
            vector<string> temp = q.front();
            q.pop();

            // Moving to a new BFS level
            // Remove all words used in the previous level
            // This allows multiple shortest paths to reuse a word
            // within the same level.
            if (temp.size() > level) {
                for (string s : wordOnLevel) words.erase(s);
                level = temp.size();
                wordOnLevel.clear();
            }

            // Once shortest paths are found, stop processing
            // deeper levels.
            if (!ans.empty() && temp.size() > ans[0].size()) break;
            string node = temp.back();

            // Reached destination word
            if (node == endWord) {
                ans.push_back(temp);
                continue;
            }

            // Generate all possible one-letter transformations
            for (int i = 0; i < node.size(); i++) {
                string next = node;
                for (char c = 'a'; c <= 'z'; c++) {
                    next[i] = c;

                    // Skip the original word itself
                    if (next == node) continue;
                    if (words.count(next)) {

                        // Extend current path
                        temp.push_back(next);
                        q.push(temp);
                        temp.pop_back();

                        // Mark for removal after current level ends
                        wordOnLevel.push_back(next);
                    }
                }
            }
        }
        return ans;
    }
};