#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

namespace first {

	class Solution {
	public:
		std::vector<int> twoSum(std::vector<int>& nums, int target) {
			std::unordered_map<int, int> diffMap;
			for (int index = 0; index < nums.size(); index++) {
				diffMap.insert({ target - nums[index], index });
			}
			std::vector<int> result(2);
			for (int index = 0; index < nums.size(); index++) {
				auto findResult = diffMap.find(nums[index]);
				if (findResult != diffMap.end()) {
					auto prevIndex = findResult->second;
					if (prevIndex == index) {
						continue;
					}
					result[0] = index;
					result[1] = prevIndex;
					return result;
				}
			}
			return result;
		}
	};

}