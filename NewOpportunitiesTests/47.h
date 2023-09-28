#pragma once
#include <string>
#include <unordered_map>
#include <map>

namespace forty_seventh {

    class TimeMap {
        std::unordered_map<std::string, std::map<int, std::string>> map;
    public:
        TimeMap() {

        }

        void set(std::string key, std::string value, int timestamp) {
            map[key].insert({ timestamp, value });
        }

        std::string get(std::string key, int timestamp) {
            auto& innerMap = map[key];
            for (auto rit = innerMap.rbegin(); rit != innerMap.rend(); rit++) {
                if (rit->first <= timestamp)
                    return rit->second;
            }
            return "";
        }
    };

}