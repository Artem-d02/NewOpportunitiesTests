#pragma once
#include <vector>
#include <queue>

namespace ninth {

	class Solution {
	public:
		std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
			int targetColor = image[sr][sc];
			if (targetColor == color) {
				return image;
			}
			std::queue<std::pair<int, int>> nodesForProcess;
			nodesForProcess.emplace(sr, sc);
			while (!nodesForProcess.empty()) {
				auto node = nodesForProcess.front();
				nodesForProcess.pop();
				int& thisColor = image[node.first][node.second];
				if (thisColor == color) {
					continue;
				}
				if (thisColor == targetColor) {
					thisColor = color;
					if (node.first + 1 < image.size())
						nodesForProcess.emplace(node.first + 1, node.second);
					if (node.first - 1 >= 0)
						nodesForProcess.emplace(node.first - 1, node.second);
					if (node.second + 1 < image[0].size())
						nodesForProcess.emplace(node.first, node.second + 1);
					if (node.second - 1 >= 0)
						nodesForProcess.emplace(node.first, node.second - 1);
				}
			}
			return image;
		}
	};

}