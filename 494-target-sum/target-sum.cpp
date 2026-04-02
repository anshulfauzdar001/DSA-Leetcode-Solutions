class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;

        if ((target + total) % 2 != 0 || abs(target) > total)
            return 0;

        int s1 = (target + total) / 2;

        vector<int> dp(s1 + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int t = s1; t >= num; t--) {
                dp[t] += dp[t - num];
            }
        }

        return dp[s1];
    }
};