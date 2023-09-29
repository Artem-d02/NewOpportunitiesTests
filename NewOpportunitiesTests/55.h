#pragma once
#include <vector>
#include <queue>

namespace fifty_fifth {

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
		std::vector<int> rightSideView(TreeNode* root) {
			std::vector<int> result;
			if (root == nullptr)
				return result;

			std::queue<TreeNode*> visited;
			visited.push(root);
			visited.push(nullptr);

			TreeNode* pre = nullptr;

			while (!visited.empty()) {
				auto cur = visited.front();
				visited.pop();

				if (cur == nullptr) {
					result.push_back(pre->val);
					if (visited.empty())
						break;
					visited.push(nullptr);
					continue;
				}

				if (cur->left) {
					visited.push(cur->left);
				}

				if (cur->right) {
					visited.push(cur->right);
				}

				pre = cur;
			}

			return result;
		}
	};

}