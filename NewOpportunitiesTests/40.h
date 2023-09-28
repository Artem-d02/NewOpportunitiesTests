#pragma once
#include <vector>
#include <queue>

namespace fortieth {

	class Solution {
		const char island = 'I';
		void bft(std::vector<std::vector<char>>& grid, const int start_x, const int start_y) {
			std::queue<std::pair<int, int>> nexts;
			auto isInRange = [&grid](int x, int y) {
				if (y < 0 || y >= grid.size())
					return false;
				if (x < 0 || x >= grid[0].size())
					return false;
				return true;
			};

			if (!isInRange(start_x, start_y))
				return;

			std::vector<int> dx = { -1, 0, 1, 0 };
			std::vector<int> dy = { 0, -1, 0, 1 };

			nexts.push(std::make_pair(start_x, start_y));

			while (!nexts.empty()) {
				auto elem = nexts.front();
				nexts.pop();

				if (grid[elem.second][elem.first] == '1') {
					grid[elem.second][elem.first] = island;

					for (int d_index = 0; d_index < dx.size(); d_index++) {
						std::pair<int, int> next = std::make_pair(elem.first + dx[d_index], elem.second + dy[d_index]);
						if (isInRange(next.first, next.second))
							nexts.push(next);
					}

				}
			}
		}
	public:
		int numIslands(std::vector<std::vector<char>>& grid) {
			int result = 0;

			for (int i = 0; i < grid.size(); i++) {
				for (int j = 0; j < grid[0].size(); j++) {
					if (grid[i][j] == '1') {
						result++;
						bft(grid, j, i);
					}
				}
			}

			return result;
		}
	};

}