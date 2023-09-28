#pragma once
#include <vector>
#include <algorithm>

namespace forty_fifth {

	class Solution {
	public:
		std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
			std::vector<std::vector<int>> result;
			result.reserve(intervals.size());

			std::sort(intervals.begin(), intervals.end());
			
			int startVal = intervals[0][0];
			int maxRightVal = intervals[0][1];
			for (int index = 0; index < intervals.size(); index++) {
				if (intervals[index][0] > maxRightVal) {
					result.push_back({ startVal, maxRightVal });
					startVal = intervals[index][0];
				}
				maxRightVal = std::max(maxRightVal, intervals[index][1]);
			}
			result.push_back({ startVal, maxRightVal });

			return result;
		}
	};

}