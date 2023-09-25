#pragma once
#include <string>
#include <unordered_map>

namespace seventeenth {

    class Solution {
    public:
        int longestPalindrome(std::string s) {
            std::unordered_map<char, int> letters;
            for (const auto& ch : s) {
                ++letters[ch];
            }
            int oddCount = 0;
            for (const auto& elem : letters) {
                if (elem.second % 2 != 0)
                    oddCount++;
            }
            if (oddCount == 0)
                return s.length();
            else
                return s.length() - oddCount + 1;
        }
    };

}