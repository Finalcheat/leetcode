/**
 * @file Implement-Stack-using-Queues.cpp
 * @brief 使用队列实现栈(https://leetcode.com/problems/implement-stack-using-queues/)
 * @author Finalcheat
 * @date 2016-04-13
 */

/**
 * Implement the following operations of a stack using queues.
 * * push(x) -- Push element x onto stack.
 * * pop() -- Removes the element on top of the stack.
 * * top() -- Get the top element.
 * * empty() -- Return whether the stack is empty.
 * Notes:
 * * You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * * Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 * * You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 */

/**
 * 使用两个队列作辅助实现，push的时候将新元素加入到q2中，然后将q1的元素移到q2中，最后交换q1、q2，其他操作就是q1的正常操作即可。
 */

class Stack {
    public:
        // Push element x onto stack.
        void push(int x) {
            q2.push(x);
            _q1MoveToQ2();
            q1.swap(q2);
        }

        // Removes the element on top of the stack.
        void pop() {
            q1.pop();
        }

        // Get the top element.
        int top() {
            return q1.front();
        }

        // Return whether the stack is empty.
        bool empty() {
            return q1.empty();
        }
        
    private:
        void _q1MoveToQ2() {
            while (!q1.empty()) {
                int value = q1.front();
                q1.pop();
                q2.push(value);
            }
        }
        
    private:
        std::queue<int> q1;
        std::queue<int> q2;
};
