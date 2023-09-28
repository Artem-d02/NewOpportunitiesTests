#pragma once
#include <list>

namespace forty_sixth {

	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};
	
	class Solution {
		bool find(TreeNode* root, TreeNode* elem, std::list<TreeNode*>& path) {
			path.push_back(root);
			if (root == elem)
				return true;
			if (root->left) {
				if (find(root->left, elem, path)) {
					return true;
				}
			}
			if (root->right) {
				if (find(root->right, elem, path)) {
					return true;
				}
			}
			path.pop_back();

			return false;
		}
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			std::list<TreeNode*> pList;
			std::list<TreeNode*> qList;

			find(root, p, pList);
			find(root, q, qList);

			TreeNode* last = root;
			while (!pList.empty() && !qList.empty()) {
				if (pList.front() != qList.front()) {
					break;
				}
				else {
					last = pList.front();
					pList.pop_front();
					qList.pop_front();
				}
			}

			return last;
		}
	};

}