#pragma once

namespace third {

	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}  
	};
		
	class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
			ListNode* resultList = nullptr;
			ListNode* nextList1Node = list1;
			ListNode* nextList2Node = list2;

			//	Initialize head element
			if (list1 == nullptr && list2 == nullptr) {
				return resultList;
			}
			else if (list1 == nullptr) {
				resultList = list2;
				return resultList;
			}
			else if (list2 == nullptr) {
				resultList = list1;
				return resultList;
			}
			else {
				if (list2->val <= list1->val) {
					resultList = list2;
					nextList2Node = list2->next;
				}
				else {
					resultList = list1;
					nextList1Node = list1->next;
				}
			}

			ListNode* currentResultNode = resultList;
			
			while (nextList1Node != nullptr || nextList2Node != nullptr) {
				if (nextList1Node == nullptr) {
					currentResultNode->next = nextList2Node;
					nextList2Node = nextList2Node->next;
				}
				else if (nextList2Node == nullptr) {
					currentResultNode->next = nextList1Node;
					nextList1Node = nextList1Node->next;
				}
				else {
					if (nextList2Node->val <= nextList1Node->val) {
						currentResultNode->next = nextList2Node;
						nextList2Node = nextList2Node->next;
					}
					else {
						currentResultNode->next = nextList1Node;
						nextList1Node = nextList1Node->next;
					}
				}
				currentResultNode = currentResultNode->next;
			}
			return resultList;
		}
	};

}