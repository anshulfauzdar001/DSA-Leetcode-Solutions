#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void buildPaths(string word,
                    string beginWord,
                    unordered_map<string, vector<string>>& parent,
                    vector<string>& temp,
                    vector<vector<string>>& ans) {
        
        if (word == beginWord) {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            return;
        }

        for (auto &p : parent[word]) {
            temp.push_back(p);
            buildPaths(p, beginWord, parent, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;

        if (!st.count(endWord))
            return ans;

        unordered_map<string, vector<string>> parent;
        unordered_set<string> currLevel, nextLevel;

        currLevel.insert(beginWord);
        bool found = false;

        while (!currLevel.empty() && !found) {

            for (auto &w : currLevel)
                st.erase(w);

            for (auto &word : currLevel) {

                string temp = word;

                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;

                        if (st.count(temp)) {
                            nextLevel.insert(temp);
                            parent[temp].push_back(word);

                            if (temp == endWord)
                                found = true;
                        }
                    }

                    temp[i] = original;
                }
            }

            currLevel = nextLevel;
            nextLevel.clear();
        }

        if (found) {
            vector<string> temp;
            temp.push_back(endWord);
            buildPaths(endWord, beginWord, parent, temp, ans);
        }

        return ans;
    }
};