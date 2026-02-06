/*
LeetCode Problem: 153. Find Minimum in Rotated Sorted Array
Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Approach:
- Use Binary Search.
- At every step, one half of the array is sorted.
- If left half is sorted, the minimum could be nums[left],
  so update answer and move right.
- Else, the minimum lies in the left half.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If left part is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right part is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};
