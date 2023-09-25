#pragma once

#include <stack>

namespace sixth {

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
		TreeNode* invertTree(TreeNode* root) {
			std::stack<TreeNode*> prevNodes;
			TreeNode* current = root;
			while (true) {
				if (current != nullptr) {
					auto temp = current->left;
					current->left = current->right;
					current->right = temp;
					prevNodes.push(current);
					current = current->left;
				}
				else {
					if (prevNodes.empty())
						break;
					current = prevNodes.top();
					current = current->right;
					prevNodes.pop();
				}
			}
			return root;
		}
	};

}