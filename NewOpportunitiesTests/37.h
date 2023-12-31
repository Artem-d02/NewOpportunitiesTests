#pragma once
#include <vector>

namespace thirty_seven {

    class Solution {
    public:
        std::vector<int> productExceptSelf(std::vector<int>& nums) {
            std::vector<int> result(nums.size(), 1);

            for (int i = 1; i < result.size(); i++) {
                result[i] = nums[i - 1] * result[i - 1];
            }

            int right = 1;
            for (int i = nums.size() - 1; i >= 0; i--) {
                result[i] *= right;
                right *= nums[i];
            }

            return result;
        }
    };

}