class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0, maxLen = 0;

        for (int num : nums) {
            if (num == 1) {
                count++;
                maxLen = max(maxLen, count);
            } else {
                count = 0;
            }
        }

        return maxLen;
    }
};