class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int i = 0, ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] % 2 == 1) k--;

            while (k < 0) {
                if (nums[i] % 2 == 1) k++;
                i++;
            }

            ans += (j - i + 1);
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};