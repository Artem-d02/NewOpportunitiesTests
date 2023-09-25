#pragma once
#include <algorithm>

namespace twenty_third {

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
		void recursiveTraverse(TreeNode* root, int& max) {
			static int depth = 0;
			depth++;
			if (depth > max)
				max = depth;
			if (root->left) {
				recursiveTraverse(root->left, max);
			}
			if (root->right) {
				recursiveTraverse(root->right, max);
			}
			depth--;
			return;
		}
		int maxDepth(TreeNode* root) {
			if (root == nullptr)
				return 0;
			int max = 0;
			recursiveTraverse(root, max);
			return max;
		}
	};

}