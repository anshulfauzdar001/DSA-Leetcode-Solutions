class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();

        // Step 1: Clean invalid numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Step 2: Mark presence
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);

            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        // Step 3: Find answer
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};