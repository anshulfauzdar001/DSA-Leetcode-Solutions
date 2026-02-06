/*
LeetCode Problem: 81. Search in Rotated Sorted Array II
Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Approach:
- Modified Binary Search with duplicates allowed.
- At each step:
  1. If middle element equals target, return true.
  2. If nums[left], nums[mid], and nums[right] are equal:
     - Shrink search space from both ends.
  3. If right half is sorted:
     - Check if target lies in this range.
  4. Else left half is sorted:
     - Check if target lies in this range.

Time Complexity:
- Average Case: O(log n)
- Worst Case (many duplicates): O(n)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Case when duplicates prevent deciding the sorted half
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            // Right half is sorted
            else if (nums[mid] <= nums[high]) {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            // Left half is sorted
            else {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return false;
    }
};
