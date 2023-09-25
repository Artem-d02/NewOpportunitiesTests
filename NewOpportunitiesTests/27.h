#pragma once
#include <vector>
#include <queue>

namespace twenty_seventh {

	class Solution {
		int nearestZero(const std::vector<std::vector<int>>& mat, const int rowIndex, const int colIndex) {
			int distance = 0;
			int curDist = 0;
			auto isInRange = [&mat](int x, int y) {
				return (0 <= x && x < mat[0].size()) && (0 <= y && y < mat.size());
			};
			int curX = 0;
			int curY = 0;
			while (true) {
				for (int x = 0, y = curDist; x <= curDist; x++, y--) {
					
					//  Right-Up
					curX = colIndex + x;
					curY = rowIndex + y;
					if (isInRange(curX, curY)) {
						if (mat[curY][curX] == 0)
							return curDist;
					}

					//  Right-Down
					curX = colIndex + x;
					curY = rowIndex - y;
					if (isInRange(curX, curY)) {
						if (mat[curY][curX] == 0)
							return curDist;
					}

					//  Left-Down
					curX = colIndex - x;
					curY = rowIndex - y;
					if (isInRange(curX, curY)) {
						if (mat[curY][curX] == 0)
							return curDist;
					}

					//  Left-Up
					curX = colIndex - x;
					curY = rowIndex + y;
					if (isInRange(curX, curY)) {
						if (mat[curY][curX] == 0)
							return curDist;
					}
				}
				curDist++;
			}
		}
	public:
		std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>&mat) {
			
			std::vector<std::vector<int>> result(mat.size());
			for (auto& row : result) {
				row.resize(mat[0].size());
			}

			for (int rowIndex = 0; rowIndex < mat.size(); rowIndex++) {
				for (int colIndex = 0; colIndex < mat[0].size(); colIndex++) {
					result[rowIndex][colIndex] = nearestZero(mat, rowIndex, colIndex);
				}
			}

			return result;
		}
	};

}

namespace twenty_seventh_boosted {

	class Solution {
	public:
		std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {

			const int NOT_PROCESSED = -1;
			std::vector<std::vector<int>> result(mat.size(), std::vector<int>(mat[0].size(), NOT_PROCESSED));
			std::queue<std::pair<int, int>> nodesToProcessNeighbors;

			for (int rowIndex = 0; rowIndex < mat.size(); rowIndex++) {
				for (int colIndex = 0; colIndex < mat[0].size(); colIndex++) {
					if (mat[rowIndex][colIndex] == 0) {
						result[rowIndex][colIndex] = 0;
						nodesToProcessNeighbors.push({ colIndex, rowIndex });
					}
				}
			}

			auto isInRange = [&mat](int x, int y) {
				return (0 <= x && x < mat[0].size()) && (0 <= y && y < mat.size());
			};

			int distance = 0;
			int x = 0;
			int y = 0;
			std::vector<std::pair<int, int>> deltas = {
				{ 0, 1 },
				{ 1, 0 },
				{ 0, -1 },
				{ -1, 0 }
			};
			while (!nodesToProcessNeighbors.empty()) {

				distance++;
				int queueSize = nodesToProcessNeighbors.size();

				for (int processIndex = 0; processIndex < queueSize; processIndex++) {
					auto point = nodesToProcessNeighbors.front();
					nodesToProcessNeighbors.pop();

					for (const auto& delta : deltas) {
						x = point.first + delta.first;
						y = point.second + delta.second;
						if (isInRange(x, y)) {
							if (result[y][x] == NOT_PROCESSED) {
								result[y][x] = distance;
								nodesToProcessNeighbors.push({ x, y });
							}
						}
					}
				}

			}

			return result;
		}
	};

}