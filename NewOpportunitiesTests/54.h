#pragma once
#include <vector>

namespace fifty_fourth {

	class Solution {
		std::vector<bool> binaryNum;
	public:
		void parseNum(int num) {
			int i = binaryNum.size() - 1;
			while (num > 0) {
				binaryNum[i--] = num % 2;
				num /= 2;
			}
		}
		std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
			binaryNum.resize(nums.size());
			int resSize = pow(2, nums.size());
			std::vector<std::vector<int>> result(resSize);
			for (int i = 0; i < resSize; i++) {
				parseNum(i);
				for (int j = 0; j < nums.size(); j++) {
					if (binaryNum[j])
						result[i].push_back(nums[j]);
				}
			}
			return result;
		}
	};

}