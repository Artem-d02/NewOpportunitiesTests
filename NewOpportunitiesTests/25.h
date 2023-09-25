#pragma once
#include <vector>

namespace twenty_fifth {

    class Solution {
    public:
        int maxSubArray(std::vector<int>& nums) {
            if (nums.size() == 0) {
                return -1;
            }
            
            //  Kadane's algo
            int curSum = nums[0];
            int maxSum = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                curSum = std::max(curSum + nums[i], nums[i]);
                maxSum = std::max(curSum, maxSum);
            }

            return maxSum;
        }
    };

}