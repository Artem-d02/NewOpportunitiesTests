#pragma once
#include <vector>
#include <algorithm>
#include <set>

namespace fifty_first {

    class Solution {
        std::set<std::pair<int, int>> visited;
        bool dft(const std::vector<int>& nums, int remaining, int curInd) {
            visited.insert({ remaining, curInd });

            if (remaining == 0)
                return true;
            
            if (curInd == nums.size() - 1 || nums[curInd] > remaining)
                return false;

            if (!visited.contains({ remaining, curInd + 1 }))
                if (dft(nums, remaining, curInd + 1))
                    return true;

            if (!visited.contains({ remaining - nums[curInd], curInd + 1}))
                if (dft(nums, remaining - nums[curInd], curInd + 1))
                    return true;

            return false;
        }
    public:
        bool canPartition(std::vector<int>& nums) {
            int sum = 0;
            for (const auto& num : nums) {
                sum += num;
            }
            if (sum % 2 != 0)
                return false;

            //  DFT
            std::sort(nums.begin(), nums.end());
            return dft(nums, sum / 2, 0);
        }
    };

}