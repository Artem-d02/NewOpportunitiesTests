#pragma once
#include <vector>
#include <queue>

namespace thirty_first {

	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
	
	class Solution {
	public:
		std::vector<std::vector<int>> levelOrder(TreeNode* root) {
			std::vector<std::vector<int>> result;
			if (root == nullptr)
				return result;

			std::queue<std::pair<TreeNode*, int>> visited;
			visited.emplace(root, 0);

			while (visited.size() != 0) {
				auto cur = visited.front();
				
				if (result.size() == cur.second)
					result.push_back({ cur.first->val });
				else
					result.back().push_back(cur.first->val);

				visited.pop();

				if (cur.first->left)
					visited.emplace(cur.first->left, cur.second + 1);
				if (cur.first->right)
					visited.emplace(cur.first->right, cur.second + 1);
			}

			return result;
		}
	};

}