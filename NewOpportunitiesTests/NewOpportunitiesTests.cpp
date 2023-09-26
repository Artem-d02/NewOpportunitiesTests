#include <vector>
#include <string>
#include <iostream>
#include "39.h"

int main() {

	thirty_ninth::Solution sol;

	thirty_ninth::TreeNode* root = new thirty_ninth::TreeNode(2);
	root->left = new thirty_ninth::TreeNode(1);
	root->right = new thirty_ninth::TreeNode(3);

	auto res = sol.isValidBST(root);

	auto print = [](const std::vector<std::vector<int>>& input) {
		for (const auto& row : input) {
			for (const auto& elem : row)
				std::cout << elem << " ";
			std::cout << std::endl;
		}
	};

	std::cout << res << std::endl;

}