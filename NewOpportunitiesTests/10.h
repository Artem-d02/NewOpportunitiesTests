#pragma once

namespace tenth {

	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			TreeNode* firstNext = nullptr;
			TreeNode* secondNext = nullptr;
			TreeNode* current = root;
			while (true) {
				if (p->val == current->val)
					return p;
				else if (p->val < current->val)
					firstNext = current->left;
				else
					firstNext = current->right;

				if (q->val == current->val)
					return q;
				else if (q->val < current->val)
					secondNext = current->left;
				else
					secondNext = current->right;
				if (firstNext != secondNext) {
					return current;
				}
				current = firstNext;
				if (current == nullptr)
					return nullptr;
			}
		}
	};

}