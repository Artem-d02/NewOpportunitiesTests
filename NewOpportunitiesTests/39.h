#pragma once
#include <stack>

namespace thirty_ninth {

	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
	
	class Solution {
		std::pair<int, int> isValidSubtree(TreeNode* root, bool& isInValid) {
			std::pair<int, int> leftMinMax;
			std::pair<int, int> rightMinMax;
			if (root->left) {
				leftMinMax = isValidSubtree(root->left, isInValid);
				if (leftMinMax.second >= root->val)
					isInValid = true;
			}
			else {
				leftMinMax.first = root->val;
				leftMinMax.second = root->val;
			}
			if (root->right) {
				rightMinMax = isValidSubtree(root->right, isInValid);
				if (rightMinMax.first <= root->val)
					isInValid = true;
			}
			else {
				rightMinMax.first = root->val;
				rightMinMax.second = root->val;
			}
			return std::make_pair(
				std::min(std::min(leftMinMax.first, rightMinMax.first), root->val),
				std::max(std::max(leftMinMax.second, rightMinMax.second), root->val)
			);
		}
	public:
		bool isValidBST(TreeNode* root) {

			bool isInvalid = false;
			isValidSubtree(root, isInvalid);
			return !isInvalid;
		}
	};

}