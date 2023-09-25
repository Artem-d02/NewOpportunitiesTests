#pragma once

namespace twelfth {

	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(nullptr) {}
	};
	
	class Solution {
	public:
		bool hasCycle(ListNode* head) {
			//	Floyd's algo
			if (head == nullptr)
				return false;
			ListNode* first = head;
			ListNode* second = head;
			while (true) {
				if (first->next == nullptr)
					return false;
				else
					first = first->next;
				if (second->next != nullptr)
					if (second->next->next == nullptr)
						return false;
					else
						second = second->next->next;
				else
					return false;

				if (first == second)
					return true;
			}
		}
	};

}