#pragma once
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

namespace thirtieth {

	class Solution {
	public:
		std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
			std::sort(nums.begin(), nums.end());
			std::set<std::vector<int>> set;

			for (int i = 0; i < nums.size() - 1; i++) {
				int j = i + 1;
				int k = nums.size() - 1;
				int sum = 0;
				while (j < k) {
					sum = nums[i] + nums[j] + nums[k];
					if (sum < 0)
						j++;
					else if (sum == 0) {
						set.insert({ nums[i], nums[j], nums[k]});
						j++;
						k--;
					}
					else
						k--;
				}
			}

			std::vector<std::vector<int>> result;
			result.reserve(set.size());
			for (const auto& elem : set)
				result.push_back(elem);
			return result;
		}
	};

}