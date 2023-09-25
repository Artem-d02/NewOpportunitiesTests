#pragma once

namespace sixteenth {

	class Solution {
	public:
		int climbStairs(int n) {
			if (n == 1)
				return 1;
			int pre = 1;
			int prePre = 1;
			int cur = 0;
			for (int i = 2; i <= n; i++) {
				cur = pre + prePre;
				prePre = pre;
				pre = cur;
			}
			return cur;
		}
	};

}