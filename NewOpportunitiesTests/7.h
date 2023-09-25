#pragma once
#include <string>
#include <unordered_map>

namespace seventh {

	class Solution {
	public:
		bool isAnagram(std::string s, std::string t) {
			if (s.length() != t.length())
				return false;
			std::unordered_map<char, int> map(t.length());
			for (const auto& ch : t) {
				++map[ch];
			}
			for (const auto& ch : s) {
				auto res = map.find(ch);
				if (res == map.end())
					return false;
				res->second--;
			}
			for (const auto& elem : map) {
				if (elem.second != 0)
					return false;
			}
			return true;
		}
	};

}