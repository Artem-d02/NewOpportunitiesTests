#pragma once
#include <vector>
#include <queue>

namespace forty_first {

	class Solution {
		enum {
			NO = 0,
			FRESH = 1,
			ROTTEN = 2
		};
		const std::pair<int, int> END_OF_STEP = { -2, -2 };
	public:
		int orangesRotting(std::vector<std::vector<int>>& grid) {
			std::queue<std::pair<int, int>> rottensNow; //  x, y of rotten now

			for (int i = 0; i < grid.size(); i++) {
				for (int j = 0; j < grid[0].size(); j++) {
					if (grid[i][j] == ROTTEN)
						rottensNow.push({ j, i });
				}
			}
			rottensNow.push(END_OF_STEP);

			std::vector<int> dx = { -1, 0, 1, 0 };
			std::vector<int> dy = { 0, -1, 0, 1 };

			auto isInRange = [&grid](int x, int y) {
				if (y < 0 || y >= grid.size())
					return false;
				if (x < 0 || x >= grid[0].size())
					return false;
				return true;
			};

			int elapsedTime = 0;
			while (!rottensNow.empty()) {
				auto elem = rottensNow.front();
				rottensNow.pop();

				if (elem == END_OF_STEP) {
					elapsedTime++;
					if (!rottensNow.empty())
						rottensNow.push(END_OF_STEP);
					continue;
				}

				for (int d_index = 0; d_index < dx.size(); d_index++) {
					std::pair<int, int> next = std::make_pair(elem.first + dx[d_index], elem.second + dy[d_index]);
					if (isInRange(next.first, next.second))
						if (grid[next.second][next.first] == FRESH) {
							grid[next.second][next.first] = ROTTEN;
							rottensNow.push(next);
						}
				}

			}

			for (int i = 0; i < grid.size(); i++) {
				for (int j = 0; j < grid[0].size(); j++) {
					if (grid[i][j] == FRESH)
						return -1;
				}
			}

			return elapsedTime - 1;
		}
	};

}