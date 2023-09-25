#pragma once
#include <vector>
#include <unordered_map>

namespace twenty_fourth {

    class Solution {
    public:
        bool containsDuplicate(std::vector<int>& nums) {
            std::unordered_map<int, int> numFreqs;
            for (const auto& num : nums) {
                ++numFreqs[num];
            }
            for (const auto& elem : numFreqs) {
                if (elem.second > 1)
                    return true;
            }
            return false;
        }
    };

}