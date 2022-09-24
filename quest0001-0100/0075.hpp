#ifndef __0075_H
#define __0075_H

/*******************************************
Description:
Given an array with n objects colored red, white or blue, sort them in-place so
that objects of the same color are adjacent, with the colors in the order red,
white and blue. Here, we will use the integers 0, 1, and 2 to represent the
color red, white, and blue respectively. Note: You are not suppose to use the
library's sort function for this problem.

Example:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Follow up:
    A rather straight forward solution is a two-pass algorithm using counting
sort. First, iterate the array counting number of 0's, 1's, and 2's, then
overwrite array with total number of 0's, then 1's and followed by 2's. Could
you come up with a one-pass algorithm using only constant space?
*******************************************/
#include "../includes.hpp"

class Solution {
public:
    void sortColors(vector<int> &nums) {
        // two pass
        // vector<int> cnt(3, 0);
        // for (int i=0; i<nums.size(); i++) {
        //     cnt[nums[i]] ++;
        // }
        // for (int i=0; i<nums.size(); i++) {
        //     if (i<cnt[0]) {
        //         nums[i] = 0;
        //     }
        //     else if (i < cnt[0]+cnt[1]) {
        //         nums[i] = 1;
        //     }
        //     else {
        //         nums[i] = 2;
        //     }
        // }

        // one pass
        int left = 0, right = (int)nums.size() - 1, cur = 0;
        while (cur <= right) {
            if (nums[cur] == 0) {
                swap(nums[cur++], nums[left++]);
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[right--]);
            } else {
                ++cur;
            }
            // for (int i=0; i<nums.size(); i++) {
            //     cout << nums[i] << " ";
            // }
            // cout << endl;
        }
    }
};

#endif
