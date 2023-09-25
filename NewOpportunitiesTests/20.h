#pragma once
#include <string>

namespace twentieth {

	class Solution {
	public:
		std::string addBinary(std::string a, std::string b) {
			std::string res;
			res.resize(std::max(a.length(), b.length()));
			char first = 0;
			char second = 0;
			char mod = 0;
			auto rit1 = a.rbegin();
			auto rit2 = b.rbegin();
			int index = res.length() - 1;
			while (rit1 != a.rend() || rit2 != b.rend()) {
				if (rit1 != a.rend()) {
					if (*rit1 == '0')
						first = 0;
					else
						first = 1;
					rit1++;
				}
				else {
					first = 0;
				}
				if (rit2 != b.rend()) {
					if (*rit2 == '0')
						second = 0;
					else
						second = 1;
					rit2++;
				}
				else {
					second = 0;
				}
				res[index--] = (first + second + mod) % 2 == 0 ? '0' : '1';
				mod = (first + second + mod) / 2;
			}
			if (mod == 1)
				res = "1" + res;
			return res;
		}
	};

}