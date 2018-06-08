/**
 * @file Min-Stack.cpp
 * @brief 最小栈(https://leetcode.com/problems/min-stack/) 
 * @author Finalcheat
 * @date 2016-04-12
 */

/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * * push(x) -- Push element x onto stack.
 * * pop() -- Removes the element on top of the stack.
 * * top() -- Get the top element.
 * * getMin() -- Retrieve the minimum element in the stack.
 */

/**
 * 同时用两个栈实现，一个栈保存元素，另一个栈保存最小元素，进栈和出栈的时候对最小元素进行对应的操作即可。
 */

class MinStack {
    public:
        void push(int x) {
            s1.push(x);
            if (s2.empty() || x <= s2.top()) {
                s2.push(x);
            }
        }

        void pop() {
            int value = s1.top();
            s1.pop();
            if (!s2.empty() && value == s2.top()) {
                s2.pop();
            }
        }

        int top() {
            return s1.top();
        }

        int getMin() {
            return s2.top();
        }

    private:
        std::stack<int> s1;
        std::stack<int> s2;
};
