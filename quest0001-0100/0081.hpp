#ifndef __0081_H
#define __0081_H

/*******************************************
Description:
Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand. (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]). You are
given a target value to search. If found in the array return true, otherwise
return false.

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Follow up:
    This is a follow up problem to Search in Rotated Sorted Array, where nums
may contain duplicates. Would this affect the run-time complexity? How and why?
*******************************************/

#include "../includes.hpp"

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            // cout << left << " " << mid << " " << right << endl;
            if (nums[mid] == target || nums[left] == target ||
                nums[right - 1] == target)
                return true;
            else if (nums[mid] < nums[left]) {
                if (nums[mid] > target)
                    right = mid;
                else if (nums[mid] < target && nums[left] < target)
                    right = mid;
                else
                    left = mid + 1;
            } else if (nums[mid] > nums[left]) {
                if (nums[mid] < target)
                    left = mid + 1;
                else if (nums[mid] > target && nums[left] > target)
                    left = mid + 1;
                else
                    right = mid;
            } else {
                left = left + 1;
            }
        }
        return false;
    }
};
#endif
