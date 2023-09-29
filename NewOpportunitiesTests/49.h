#pragma once
#include <vector>

namespace forty_ninth {

    class Solution {
    public:
        void sortColors(std::vector<int>& nums) {
            int zeroCounter = 0;
            int oneCounter = 0;
            int twoCounter = 0;

            for (const auto& num : nums) {
                switch (num) {
                case 0:
                    zeroCounter++;
                    break;
                case 1:
                    oneCounter++;
                    break;
                case 2:
                    twoCounter++;
                }
            }

            for (int i = 0; i < zeroCounter; i++) {
                nums[i] = 0;
            }
            for (int i = zeroCounter; i < zeroCounter + oneCounter; i++) {
                nums[i] = 1;
            }
            for (int i = zeroCounter + oneCounter; i < nums.size(); i++) {
                nums[i] = 2;
            }
        }
    };

}