#pragma once
#include <vector>

namespace fifty_third {

    class Solution {
    public:
        std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
            //  Calculate result size
            int m = matrix.size();
            int n = matrix[0].size();
            int len = 0;
            while (m > 0) {
                while (n > 0) {
                    len += n--;
                }
                len += --m;
            }

            std::vector<int> result;
            result.reserve(len);

            int startRowIndex = 0;
            int startColIndex = 0;
            int colCount = matrix[0].size();
            int rowCount = matrix.size();
            while (colCount > 0 && rowCount > 0) {
                for (int colIndex = startColIndex; colIndex < startColIndex + colCount; colIndex++) {
                    result.push_back(matrix[startRowIndex][colIndex]);
                }
                for (int rowIndex = startRowIndex + 1; rowIndex < startRowIndex + rowCount; rowIndex++) {
                    result.push_back(matrix[rowIndex][startColIndex + colCount - 1]);
                }
                if (startRowIndex != startRowIndex + rowCount - 1) {
                    for (int colIndex = startColIndex + colCount - 2; colIndex >= startColIndex; colIndex--) {
                        result.push_back(matrix[startRowIndex + rowCount - 1][colIndex]);
                    }
                }
                if (startColIndex + colCount - 1 != startColIndex) {
                    for (int rowIndex = startRowIndex + rowCount - 2; rowIndex >= startRowIndex + 1; rowIndex--) {
                        result.push_back(matrix[rowIndex][startColIndex]);
                    }
                }
                startColIndex++;
                startRowIndex++;
                colCount -= 2;
                rowCount -= 2;
            }

            return result;
        }
    };

}