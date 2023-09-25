#pragma once
#include <vector>

namespace twenty_sixth {

	class Solution {
	public:
		std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
			
			std::vector<std::vector<int>> result;
			result.reserve(intervals.size() + 1);

			int i = 0;

			while (i < intervals.size()) {
				if (intervals[i][1] < newInterval[0]) {
					result.push_back(intervals[i]);
				}
				else if (intervals[i][0] > newInterval[1]) {
					break;
				}
				else {
					newInterval[0] = std::min(newInterval[0], intervals[i][0]);
					newInterval[1] = std::max(newInterval[1], intervals[i][1]);
				}
				i++;
			}

			result.push_back(newInterval);

			while (i < intervals.size()) {
				result.push_back(intervals[i++]);
			}

			return result;
			
		}
	};

}