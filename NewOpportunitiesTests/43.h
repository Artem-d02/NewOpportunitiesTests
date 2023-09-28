#pragma once
#include <vector>
#include <algorithm>
#include <set>

namespace forty_third {

    class Solution {
    public:
        std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
            std::vector<std::vector<std::vector<int>>> targets(target + 1);

            auto isInRange = [&targets](int x) {
                if (x < 0 || x >= targets.size())
                    return false;
                return true;
            };
            
            for (int candInd = 0; candInd < candidates.size(); candInd++) {
                if (isInRange(candidates[candInd]))
                    targets[candidates[candInd]].push_back({ candidates[candInd] });
            }

            for (int i = 0; i <= target; i++) {
                for (int candInd = 0; candInd < candidates.size(); candInd++) {
                    if (isInRange(i - candidates[candInd])) {
                        for (const auto& elem : targets[i - candidates[candInd]]) {
                            targets[i].push_back(elem);
                            targets[i].back().push_back(candidates[candInd]);
                        }
                    }
                }

            }

            std::vector<std::vector<int>> result;
            result.reserve(targets.back().size());

            std::set<std::vector<int>> resultSet;

            for (auto& path : targets.back()) {
                std::sort(path.begin(), path.end());
                resultSet.insert(path);
            }

            for (const auto& elem : resultSet) {
                result.push_back(elem);
            }

            return result;
        }
    };

}