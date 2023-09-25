#pragma once
#include <vector>


namespace fourth {

	class Solution {
	public:
		int maxProfit(std::vector<int>& prices) {
			size_t first = 0;
			size_t second = 0;
			int best_profit = 0;
			int profit = 0;

			while (second != prices.size()) {
				profit = prices[second] - prices[first];
				if (profit < 0)
					profit = 0;
				if (profit > best_profit)
					best_profit = profit;
				if (prices[second] < prices[first])
					first = second;
				second++;
			}

			return best_profit;
		}
	};

}