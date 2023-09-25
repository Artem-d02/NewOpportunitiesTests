#pragma once
#include <string>
#include <list>

namespace second {

	class Solution {
	public:
		bool isValid(std::string s) {
			enum class Brackets { R, S, C };
			std::list<Brackets> seq;
			for (const auto& ch : s) {
				switch (ch) {
				case '(':
					seq.push_back(Brackets::R);
					break;
				case ')':
					if (seq.empty()) {
						return false;
					}
					if (seq.back() != Brackets::R) {
						return false;
					}
					else {
						seq.pop_back();
					}
					break;
				case '[':
					seq.push_back(Brackets::S);
					break;
				case ']':
					if (seq.empty()) {
						return false;
					}
					if (seq.back() != Brackets::S) {
						return false;
					}
					else {
						seq.pop_back();
					}
					break;
				case '{':
					seq.push_back(Brackets::C);
					break;
				case '}':
					if (seq.empty()) {
						return false;
					}
					if (seq.back() != Brackets::C) {
						return false;
					}
					else {
						seq.pop_back();
					}
					break;
				}
			}
			if (seq.empty()) {
				return true;
			}
			else {
				return false;
			}
		}
	};

}