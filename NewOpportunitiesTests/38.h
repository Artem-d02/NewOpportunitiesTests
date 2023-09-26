#pragma once

namespace thirty_eighth {

	class MinStack {

		struct StackNode final {
			int val;
			int preMin;
			StackNode* next{ nullptr };
			StackNode(const int newVal) : val(newVal), preMin(newVal) {};
		};

		StackNode* head;

	public:
		MinStack() : head(nullptr) {}

		void push(int val) {
			StackNode* newNode = new StackNode(val);
			newNode->next = head;
			head = newNode;

			if (head->next != nullptr)
				if (head->next->preMin < head->preMin)
					head->preMin = head->next->preMin;
		}

		void pop() {
			StackNode* tmp = head;
			head = head->next;
			delete tmp;
		}

		int top() {
			return head->val;
		}

		int getMin() {
			return head->preMin;
		}
	};

}