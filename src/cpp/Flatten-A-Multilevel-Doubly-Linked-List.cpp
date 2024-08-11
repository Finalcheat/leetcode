/**
 * @file Flatten-A-Multilevel-Doubly-Linked-List.cpp
 * @brief 扁平化多级双向链表(https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/)
 * @author Finalcheat
 * @date 2024-08-11
 */

/**
 * 循环中扁平化调整指针，同时将next压入栈，最后找到结尾节点出栈接上。
 */


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
    public:
        Node* flatten(Node* head) {
            Node* ptr = head;
            Node* tail = head;
            stack<Node*> stk;
            while (ptr != nullptr || !stk.empty()) {
                while (ptr != nullptr) {
                    if (ptr->child != nullptr) {
                        Node* next = ptr->next;
                        if (next != nullptr) {
                            stk.push(next);
                        }
                        ptr->next = ptr->child;
                        ptr->child->prev = ptr;
                        ptr->child = nullptr;
                    }
                    tail = ptr;
                    ptr = ptr->next;
                }
                if (!stk.empty()) {
                    Node* next = stk.top();
                    stk.pop();
                    next->prev = tail;
                    tail->next = next;
                    ptr = next;
                }
            }
            return head;
        }
};
