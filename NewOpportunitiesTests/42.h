#pragma once
#include <vector>

namespace forty_second {

	class Solution {
	public:
		int findMax(std::vector<int>& nums) {
			int leftElem = nums[0];

			if (nums.size() == 1)
				return 0;

			if (nums[nums.size() - 1] > nums[0])
				return nums.size() - 1;

			int mid = nums.size() / 2;
			int startInd = 0;
			int endInd = nums.size() - 1;
			while (true) {
				if (nums[mid] >= leftElem && nums[mid + 1] < leftElem) {
					return mid;
				}
				else if (nums[mid] < leftElem) {
					endInd = mid;
				}
				else {
					startInd = mid;
				}
				mid = (startInd + endInd) / 2;
			}
		}

		int bs_mod(std::vector<int>& nums, const int maxInd, const int target) {

			if (nums.size() == 1) {
				if (nums[0] == target) {
					return 0;
				}
				else {
					return -1;
				}
			}

			int startInd = (maxInd + 1) % nums.size();
			int endInd = maxInd;
			int mid = (nums.size() - 1 / 2 + startInd) % nums.size();

			while (endInd != startInd) {
				if (nums[mid] == target)
					return mid;
				else if (nums[mid] < target)
					startInd = (mid + 1) % nums.size();
				else
					endInd = mid;
				int delta = (endInd - startInd) < 0 ? (nums.size() + endInd - startInd) : (endInd - startInd);
				mid = (delta / 2 + startInd) % nums.size();
			}

			if (nums[startInd] == target)
				return startInd;
			else
				return -1;
		}

		int search(std::vector<int>& nums, int target) {
			int maxIndex = findMax(nums);
			return bs_mod(nums, maxIndex, target);
		}
	};

}