#include <vector>
#include <string>
#include <iostream>
#include "56.h"

int main() {

	fifty_sixth::Solution sol;

	std::string input = "ac";
	auto result = sol.longestPalindrome(input);

	auto print = [](const auto& input) {
		for (const auto& row : input) {
			for (const auto& elem : row)
				std::cout << elem << " ";
			std::cout << std::endl;
		}
	};

	std::cout << result << std::endl;

	//print(result);
}