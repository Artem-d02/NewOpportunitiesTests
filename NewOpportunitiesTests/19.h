#pragma once
#include <vector>
#include <unordered_map>

namespace nineteenth {

    class Solution {
    public:
        int majorityElement(std::vector<int>& nums) {
            std::unordered_map<int, int> elems;
            for (const auto& num : nums) {
                ++elems[num];
            }
            for (const auto& elem : elems) {
                if (elem.second > nums.size() / 2)
                    return elem.first;
            }
            return nums[0];
        }
    };

}