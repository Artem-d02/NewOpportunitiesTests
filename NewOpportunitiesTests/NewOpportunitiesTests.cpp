﻿#include <vector>
#include <string>
#include <iostream>
#include "33.h"

int main() {

	thirty_third::Solution sol;

	std::vector<std::string> input = { "-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-" };

	auto res = sol.evalRPN(input);

	auto print = [](const std::vector<std::vector<int>>& input) {
		for (const auto& row : input) {
			for (const auto& elem : row)
				std::cout << elem << " ";
			std::cout << std::endl;
		}
	};

	std::cout << res << std::endl;

}