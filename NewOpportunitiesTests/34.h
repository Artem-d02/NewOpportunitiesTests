#pragma once
#include <vector>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <algorithm>

namespace thirty_fourth {

	class Solution {
	public:
		bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
			//  Kahn's algo
			std::unordered_map<int, std::vector<int>> graph;
			for (int i = 0; i < prerequisites.size(); i++) {
				if (graph.contains(prerequisites[i][0]))
					graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
				else
					graph.insert({ prerequisites[i][0], { prerequisites[i][1] } });
			}

			std::stack<int> stack;
			std::unordered_set<int> visited;

			while (!graph.empty()) {
				auto& cur = *graph.begin();
				stack.push(cur.first);
				visited.insert(cur.first);

				//  DFT
				while (!stack.empty()) {
					int curVert = stack.top();
					stack.pop();
					
					if (!graph.contains(curVert))
						continue;

					for (const auto& neighbor : graph[curVert]) {
						if (visited.contains(neighbor)) {
							return false;
						}
						else {
							visited.insert(neighbor);
							stack.push(neighbor);
						}
					}

				}

				//	Delete traversed vertices
				for (const auto& elem : visited) {
					graph.erase(elem);
				}
				visited.clear();

			}

			return true;

		}
	};

}