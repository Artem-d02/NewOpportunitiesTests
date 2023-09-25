#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace twenty_ninth {

	class Solution {
	public:
		int lengthOfLongestSubstring(std::string s) {
			std::string subStr;
			int startIndex = 0;
			int endIndex = 0;
			int maxSize = 0;
			for (const auto& ch : s) {
				size_t searchIndex = subStr.find(ch);
				if (searchIndex != std::string::npos) {
					startIndex += searchIndex + 1;
					subStr.erase(0, searchIndex + 1);
				}
				subStr.push_back(ch);
				endIndex++;
				maxSize = std::max(maxSize, endIndex - startIndex);
			}
			return maxSize;
		}
	};

}