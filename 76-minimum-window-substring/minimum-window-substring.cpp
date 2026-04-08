class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, have;

        // Step 1: store target frequency
        for (char c : t) need[c]++;

        int required = need.size();   // unique chars needed
        int formed = 0;

        int i = 0, j = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (j < s.size()) {
            char c = s[j];
            have[c]++;

            // check if this char is satisfied
            if (need.count(c) && have[c] == need[c]) {
                formed++;
            }

            // Step 2: shrink window
            while (formed == required) {
                // update answer
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                char left = s[i];
                have[left]--;

                if (need.count(left) && have[left] < need[left]) {
                    formed--;
                }

                i++;
            }

            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};