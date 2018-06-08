/**
 * @file Implement-Queue-using-Stacks.cpp
 * @brief 使用栈实现队列(https://leetcode.com/problems/implement-queue-using-stacks/)
 * @author Finalcheat
 * @date 2016-04-10
 */

/**
 * Implement the following operations of a queue using stacks.
 * * push(x) -- Push element x to the back of queue.
 * * pop() -- Removes the element from in front of queue.
 * * peek() -- Get the front element.
 * * empty() -- Return whether the queue is empty.
 * Notes:
 * * You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * * Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 * * You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 */

/**
 * 利用两个栈辅助实现，push操作的元素存储在栈s1，pop和peek操作栈s2，若s2为空，将s1栈的顺序逆序到s2中，然后对s2进行出队操作等。
 */

class Queue {
    public:
        // Push element x to the back of queue.
        void push(int x) {
            s1.push(x);
        }

        // Removes the element from in front of queue.
        void pop(void) {
            if (s2.empty()) {
                _s1MoveToS2();
            }
            s2.pop();
        }

        // Get the front element.
        int peek(void) {
            if (s2.empty()) {
                _s1MoveToS2();
            }
            return s2.top();
        }

        // Return whether the queue is empty.
        bool empty(void) {
            return s1.size() + s2.size() == 0;
        }
        
    private:
        void _s1MoveToS2() {
            while (!s1.empty()) {
                int value = s1.top();
                s1.pop();
                s2.push(value);
            }
        }
        
    private:
        std::stack<int> s1;
        std::stack<int> s2;
};
