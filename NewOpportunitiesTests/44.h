#pragma once
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

namespace forty_fourth {

	class Solution {
	public:
		std::vector<std::vector<int>> permute(std::vector<int>& nums) {

			std::vector<std::vector<int>> result;
			result.push_back({ nums[0] });

			for (int numInd = 1; numInd < nums.size(); numInd++) {
				for (int vecInd = 0; vecInd < result.size(); vecInd += result[0].size() + 1) {
					for (int copyIndex = 0; copyIndex < result[vecInd].size(); copyIndex++) {
						auto curIt = result.begin() + vecInd;
						result.insert(curIt, result[vecInd]);
					}
				}
				int curSize = result[0].size() + 1;
				for (int vecInd = 0; vecInd < result.size(); vecInd++) {
					result[vecInd].insert(result[vecInd].begin() + (vecInd % curSize), nums[numInd]);
				}
			}

			return result;
		}
	};

}