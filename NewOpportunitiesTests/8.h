#pragma once
#include <vector>
#include <iostream>

namespace eighth {

	class Solution {
	public:
		int search(std::vector<int>& nums, int target) {
			int start = 0;
			int end = nums.size() - 1;
			int mid = 0;
			do {
				mid = (end - start) / 2;
				//std::cout << "start: " << start << " end: " << end << " mid: " << mid << std::endl;
				if (target > nums[start + mid])
					start += mid;
				else
					end -= mid;
				if (nums[start] == target)
					return start;
				
			} while (end - start > 1);
			if (nums[end] == target)
				return end;
			else
				return -1;
		}
	};

}