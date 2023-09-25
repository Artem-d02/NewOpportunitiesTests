#pragma once
#include <vector>
#include <string>
#include <stack>

namespace thirty_third {

	class Solution {
	public:
		int parseStringToNum(const std::string& str) const noexcept {
			int result = 0;
			auto cit = str.cbegin();
			int factor = 1;
			if (*cit == '-') {
				factor = -1;
				cit++;
			}
			for (; cit != str.cend(); cit++) {
				result *= 10;
				result += *cit - '0';
			}
			return result * factor;
		}
		int evalRPN(std::vector<std::string>& tokens) {
			std::stack<int> stack;

			int first = 0;
			int second = 0;
			for (const auto& elem : tokens) {
				if (elem == "+") {
					first = stack.top();
					stack.pop();
					second = stack.top();
					stack.pop();
					stack.push(first + second);
				}
				else if (elem == "-") {
					first = stack.top();
					stack.pop();
					second = stack.top();
					stack.pop();
					stack.push(second - first);
				}
				else if (elem == "*") {
					first = stack.top();
					stack.pop();
					second = stack.top();
					stack.pop();
					stack.push(first * second);
				}
				else if (elem == "/") {
					first = stack.top();
					stack.pop();
					second = stack.top();
					stack.pop();
					stack.push(second / first);
				}
				else {
					stack.push(parseStringToNum(elem));
				}
			}
			return stack.top();
		}
	};

}