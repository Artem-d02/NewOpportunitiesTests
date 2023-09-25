#pragma once
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

namespace thirty_second {

	class Node {
	public:
		int val;
		std::vector<Node*> neighbors;
		Node() {
			val = 0;
			neighbors = std::vector<Node*>();
		}
		Node(int _val) {
			val = _val;
			neighbors = std::vector<Node*>();
		}
		Node(int _val, std::vector<Node*> _neighbors) {
			val = _val;
			neighbors = _neighbors;
		}
	};

	class Solution {
	public:
		Node* cloneGraph(Node* node) {
			if (node == nullptr)
				return node;

			Node* result = new Node(node->val);

			std::queue<Node*> lastVisited;
			std::queue<Node*> lastVisitedCopy;
			std::unordered_map<Node*, Node*> processed;

			lastVisited.push(node);
			lastVisitedCopy.push(result);

			while (!lastVisited.empty()) {
				auto cur = lastVisited.front();
				lastVisited.pop();
				auto curCopy = lastVisitedCopy.front();
				lastVisitedCopy.pop();

				processed.insert({ cur, curCopy });

				for (const auto& neighbor : cur->neighbors) {
					if (processed.contains(neighbor)) {
						curCopy->neighbors.push_back(processed[neighbor]);
					}
					else {
						Node* newNode = new Node(neighbor->val);
						curCopy->neighbors.push_back(newNode);
						processed.insert({ neighbor, newNode });

						lastVisited.push(neighbor);
						lastVisitedCopy.push(newNode);
					}
				}
			}

			return result;
		}
	};

}