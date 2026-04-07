class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();
        vector<int> freq(3, 0); // a, b, c
        
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            freq[s[right] - 'a']++;

            // jab window valid ho jaye
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                ans += (n - right);   // IMPORTANT
                freq[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};