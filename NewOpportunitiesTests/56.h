#pragma once
#include <string>

namespace fifty_sixth {

	class Solution {
		bool isPalindrome(const std::string& s, int first, int second) {
			while (second > first) {
				if (s[first] != s[second])
					return false;
				first++;
				second--;
			}
			return true;
		}
	public:
		std::string longestPalindrome(std::string s) {
			if (s.length() == 1)
				return s;

			auto isInRange = [&s](int i) {
				if (0 <= i && i < s.length())
					return true;
				else
					return false;
			};

			std::string result;

			for (int i = 0; i < s.size(); i++) {
				for (int j = i; j < s.size(); j++) {
					if (isPalindrome(s, i, j)) {
						if (j - i + 1 > result.length())
							result = s.substr(i, j - i + 1);
					}
				}
			}
			
			return result;
		}
	};

}