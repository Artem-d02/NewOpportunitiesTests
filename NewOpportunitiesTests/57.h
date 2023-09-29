#pragma once
#include <vector>

namespace fifty_seventh {

    class Solution {
    public:
        int uniquePaths(int m, int n) {
            std::vector<std::vector<int>> pathsCounts(m, std::vector<int>(n, 0));
            pathsCounts[0][0] = 1;

            for (int i = 0; i < pathsCounts.size(); i++) {
                pathsCounts[i][0] = 1;
            }

            for (int i = 0; i < pathsCounts[0].size(); i++) {
                pathsCounts[0][i] = 1;
            }

            for (int y = 1; y < m; y++) {
                for (int x = 1; x < n; x++) {
                    pathsCounts[y][x] = pathsCounts[y - 1][x] + pathsCounts[y][x - 1];
                }
            }

            return pathsCounts.back().back();
        }
    };

}