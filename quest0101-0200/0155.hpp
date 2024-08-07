#ifndef __0155_H
#define __0155_H

/****************************************************
Description:
Design a stack that supports push, pop, top, and retrieving the minimum element
in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output
[null,null,null,null,-3,null,0,-2]
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:
Methods pop, top and getMin operations will always be called on non-empty
stacks.
****************************************************/

#include "../includes.hpp"

class MinStack {
public:
    vector<int> data;
    vector<int> minVal;
    MinStack() {}
    void push(int x) {
        data.push_back(x);
        if (data.size() == 1 || minVal.back() >= x) {
            minVal.push_back(x);
        }
    }

    void pop() {
        if (data.back() == minVal.back()) {
            minVal.pop_back();
        }
        data.pop_back();
    }

    int top() { return data.back(); }

    int getMin() { return minVal.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#endif