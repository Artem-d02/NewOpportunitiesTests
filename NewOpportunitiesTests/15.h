#pragma once
#include <string>
#include <unordered_map>

namespace fifteenth {

    class Solution {
    public:
        bool canConstruct(std::string ransomNote, std::string magazine) {
            std::unordered_map<char, int> letters;
            for (const auto& ch : ransomNote) {
                ++letters[ch];
            }
            for (const auto& ch : magazine) {
                auto elem = letters.find(ch);
                if (elem != letters.end()) {
                    elem->second--;
                }
            }
            for (const auto& let : letters) {
                if (let.second > 0)
                    return false;
            }
            return true;
        }
    };

}