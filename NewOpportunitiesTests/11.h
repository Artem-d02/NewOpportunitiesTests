#pragma once
#include <stack>
#include <unordered_map>

namespace eleventh {

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
		int countMaxDepthRecursievly(TreeNode* root, bool firstCall = false) {
			static int maxDepth = 1;
			static int depth = 1;
			if (firstCall) {
				maxDepth = 1;
				depth = 1;
			}
			if (root->left) {
				depth++;
				if (maxDepth < depth)
					maxDepth = depth;
				countMaxDepthRecursievly(root->left);
				depth--;
			}
			if (root->right) {
				depth++;
				if (maxDepth < depth)
					maxDepth = depth;
				countMaxDepthRecursievly(root->right);
				depth--;
			}
			return maxDepth;
		}
		bool isBalanced(TreeNode* root) {
			std::stack<TreeNode*> visited;
			TreeNode* current = root;
			int maxDepth = 0;
			while (true) {
				if (current != nullptr) {

					int leftDepth = current->left == nullptr ? 0 : countMaxDepthRecursievly(current->left, true);
					int rightDepth = current->right == nullptr ? 0 : countMaxDepthRecursievly(current->right, true);

					if (abs(leftDepth - rightDepth) > 1)
						return false;

					visited.push(current);
					current = current->left;
					maxDepth++;
				}
				else {
					if (visited.empty())
						break;
					current = visited.top();
					current = current->right;
					visited.pop();
				}
			}
			return true;
		}
	};

}