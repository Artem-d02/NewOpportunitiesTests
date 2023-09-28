#include <vector>
#include <string>
#include <iostream>
#include "46.h"

int main() {

	forty_sixth::Solution sol;

	std::vector<std::vector<int>> input = {
		{1,4} ,{0,2},{3,5}
	};

	forty_sixth::TreeNode* root = new forty_sixth::TreeNode(1);
	root->left = new forty_sixth::TreeNode(2);
	root->right = new forty_sixth::TreeNode(3);
	root->left->left = new forty_sixth::TreeNode(4);

	auto result = sol.lowestCommonAncestor(root, root->left, root->left->left);

	auto print = [](const std::vector<std::vector<int>>& input) {
		for (const auto& row : input) {
			for (const auto& elem : row)
				std::cout << elem << " ";
			std::cout << std::endl;
		}
	};

	//print(res);
	//std::cout << res << std::endl;

	//print(result);
	std::cout << result->val << std::endl;
}