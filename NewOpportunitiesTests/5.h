#pragma once
#include <string>
#include <algorithm>

namespace fifth {

    class Solution {
    public:
        bool isPalindrome(std::string s) {
            std::string other;
            for (const auto& ch : s) {
                if (std::isalnum(ch))
                    other.push_back(std::tolower(ch));
            }

            for (int i = 0, j = other.length() - 1; i < j; i++, j--) {
                if (other[i] != other[j])
                    return false;
            }
            return true;
        }
    };

}