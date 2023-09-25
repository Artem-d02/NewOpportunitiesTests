#pragma once
#include <stack>

namespace thirteenth {

    class MyQueue {
        std::stack<int> first;  //  used for pushing
        std::stack<int> second; //  storing flipped items
    public:
        MyQueue() {

        }

        void push(int x) {
            while (!second.empty()) {
                first.push(second.top());
                second.pop();
            }

            first.push(x);

            while (!first.empty()) {
                second.push(first.top());
                first.pop();
            }
        }

        int pop() {
            int front = second.top();
            second.pop();
            return front;
        }

        int peek() {
            return second.top();

        }

        bool empty() {
            return second.empty();
        }
    };

}