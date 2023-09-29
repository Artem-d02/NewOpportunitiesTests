#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

namespace forty_eighth {

	class Solution {
	public:
		std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) {
			//  Create a map email -> acc_ind
			std::unordered_map<std::string, std::vector<int>> emailsMap;
			for (int i = 0; i < accounts.size(); i++) {
				for (int j = 1; j < accounts[i].size(); j++) {
					emailsMap[accounts[i][j]].push_back(i);
				}
			}

			std::vector<std::vector<std::string>> result;
			std::vector<std::string> curEmails;

			while (!emailsMap.empty()) {
				std::string name = accounts[emailsMap.begin()->second[0]][0];

				curEmails.push_back(emailsMap.begin()->first);
				int preSize = 0;
				do {
					preSize = curEmails.size();
					for (const auto& accIndex : emailsMap[curEmails.back()]) {
						for (int j = 1; j < accounts[accIndex].size(); j++) {
							if (std::find(curEmails.begin(), curEmails.end(), accounts[accIndex][j]) == curEmails.end()) {
								curEmails.push_back(accounts[accIndex][j]);
							}
						}
					}
				} while (curEmails.size() != preSize);

				result.push_back({ name });
				for (const auto& email : curEmails) {
					result.back().push_back(email);
					emailsMap.erase(email);
				}

				std::sort(result.back().begin() + 1, result.back().end());

				curEmails.clear();

			}

			return result;
		}
	};

}