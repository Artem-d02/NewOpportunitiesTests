#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

namespace fiftieth {

	class Solution {
	public:
		bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
			auto isInRange = [&s](const int index) {
				if (index < 0 || index >= s.length())
					return false;
				else
					return true;
			};

			std::vector<bool> possiblePositions(s.length() + 1, false);
			possiblePositions[0] = true;
			
			for (int strInd = 0; strInd < s.length(); strInd++) {
				for (const auto& word : wordDict) {
					int startInd = strInd - word.length() + 1;
					if (isInRange(startInd)) {
						if (possiblePositions[startInd] && s.substr(startInd, word.length()) == word) {
							possiblePositions[strInd + 1] = true;
							break;
						}
					}
				}
			}
			return possiblePositions[s.length()];
		}
	};

}