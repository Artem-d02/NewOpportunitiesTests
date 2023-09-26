#pragma once
#include <vector>

namespace thirty_sixth {

    class Solution {
    public:
        int coinChange(std::vector<int>& coins, int amount) {
            std::vector<int> preValues(amount + 1, 1e5);

            preValues[0] = 0;
            for (int i = 1; i < preValues.size(); i++) {
                int curMin = 1e5;
                for (const auto& coin : coins) {
                    int preIndex = i - coin;
                    if (preIndex < 0)
                        continue;
                    curMin = std::min(curMin, preValues[preIndex] + 1);
                }
                preValues[i] = curMin;
            }

            if (preValues.back() == 1e5)
                return -1;
            else
                return preValues.back();
        }
    };

}