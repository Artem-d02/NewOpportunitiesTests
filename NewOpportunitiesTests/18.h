#pragma once

namespace eighteenth {

	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	
	class Solution {
	public:
		ListNode* reverseList(ListNode* head) {
			if (head == nullptr)
				return head;
			ListNode* temp = head;
			if (temp->next == nullptr)
				return head;
			ListNode* res = temp->next;
			temp->next = nullptr;
			if (res->next == nullptr) {
				res->next = temp;
				return res;
			}
			ListNode* cur = res->next;

			while (cur != nullptr) {
				res->next = temp;
				temp = res;
				res = cur;
				cur = cur->next;
			}
			res->next = temp;
			return res;
		}
	};

}