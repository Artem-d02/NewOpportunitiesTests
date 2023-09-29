#pragma once
#include <string>

namespace fifty_second {

	class Solution {
	public:
		int myAtoi(std::string s) {
			if (s.length() == 0)
				return 0;

			int index = 0;
			while (s[index] == ' ' && index < s.length()) {
				index++;
			}
			
			int factor = 1;
			long long int number = 0;
			if (!std::isdigit(s[index])) {
				switch (s[index])
				{
				case '-':
					factor = -1;
					break;
				case '+':
					factor = 1;
					break;
				default:
					return number;
				}
				index++;
				if (index >= s.length())
					return number;
			}

			while (std::isdigit(s[index])) {
				number *= 10;
				number += s[index] - '0';
				index++;
				if (number * factor < INT_MIN)
					return INT_MIN;
				else if (number * factor > INT_MAX)
					return INT_MAX;
				if (index >= s.length())
					break;
			}

			return number * factor;
		}
	};

}