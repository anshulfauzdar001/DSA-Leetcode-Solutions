/*
LeetCode Problem: 154. Find Minimum in Rotated Sorted Array II
Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

Approach:
- Modified Binary Search to handle duplicates.
- At each step:
  1. If nums[low], nums[mid], and nums[high] are equal,
     we cannot determine the sorted half → shrink bounds.
  2. If left half is sorted, update answer and move right.
  3. Else, the minimum lies in the left half.

Time Complexity:
- Average Case: O(log n)
- Worst Case (many duplicates): O(n)

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

            // Case when duplicates block decision
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                ans = min(ans, nums[low]);
                low++;
                high--;
            }
            // Left half is sorted
            else if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};
