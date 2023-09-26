#pragma once
#include <string>
#include <unordered_map>

namespace thirty_fifth {

	class Trie {
		static const int LETS_NUM = 26;
		static const char NO_VAL = 0;

		struct TrieNode final {
			char val;
			bool endsHere{ false };
			std::unordered_map<char, TrieNode*> children;
			TrieNode(const char newVal) : val(newVal), children(LETS_NUM) {}
		};

		TrieNode* root;

	public:
		Trie() : root(new TrieNode(NO_VAL)) {}

		void insert(std::string word) {
			if (word.empty())
				return;

			TrieNode* cur = root;

			for (const auto& ch : word) {
				if (!cur->children.contains(ch))
					cur->children[ch] = new TrieNode(ch);
				cur = cur->children[ch];
			}
			cur->endsHere = true;
		}

		bool search(std::string word) {
			TrieNode* cur = root;
			for (const auto& ch : word) {
				if (!cur->children.contains(ch))
					return false;
				cur = cur->children[ch];
			}
			if (cur->endsHere)
				return true;
			else
				return false;
		}

		bool startsWith(std::string prefix) {
			TrieNode* cur = root;
			for (const auto& ch : prefix) {
				if (!cur->children.contains(ch))
					return false;
				cur = cur->children[ch];
			}
			return true;
		}
	};

}