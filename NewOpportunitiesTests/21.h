#pragma once
#include <unordered_map>
#include <stack>

namespace twenty_first {

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
		void recursiveTraverse(TreeNode* root, std::unordered_map<TreeNode*, std::pair<int, int>>& depthMap) {
			static int depth = 0;
			//	Left subtree
			if (root->left) {
				recursiveTraverse(root->left, depthMap);
				depthMap[root].first = ++depth;
			}
			else {
				depthMap[root].first = 0;
			}
			//	Right subtree
			if (root->right) {
				depth = 0;
				recursiveTraverse(root->right, depthMap);
				depthMap[root].second = ++depth;
			}
			else {
				depthMap[root].second = 0;
			}
			depth = std::max(depthMap[root].first, depthMap[root].second);
			return;
		}

		int diameterOfBinaryTree(TreeNode* root) {
			std::unordered_map<TreeNode*, std::pair<int, int>> depthMap;
			recursiveTraverse(root, depthMap);
			int maxDiam = 0;
			int curLen = 0;
			std::stack<TreeNode*> prevNodes;
			TreeNode* current = root;
			while (true) {
				if (current != nullptr) {
					curLen = depthMap[current].first + depthMap[current].second + 1;
					if (curLen > maxDiam)
						maxDiam = curLen;
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
			return maxDiam;
		}
	};

}