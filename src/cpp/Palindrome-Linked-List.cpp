/**
 * @file Palindrome-Linked-List.cpp
 * @brief 证明单链表是否是回文(https://leetcode.com/problems/palindrome-linked-list/) 
 * @author Finalcheat
 * @date 2016-05-14
 */

/**
 * Given a singly linked list, determine if it is a palindrome.
 */

/**
 * 简单的解法是第一次遍历单链表用栈存储链表节点的值，第二次遍历的时候与出栈的元素值比较，不相等则为false，遍历完成之后为true。
 * 还有一种不使用额外空间的方法，遍历一次链表找到中点，从中点开始将单链表逆序，最终进行比较即可。但是这样会改变原链表的指向。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            std::stack<int> s;
            ListNode* node = head;
            while (node) {
                s.push(node->val);
                node = node->next;
            }
            node = head;
            while (node) {
                int value = s.top();
                if (value != node->val) {
                    return false;
                }
                s.pop();
                node = node->next;
            }
            return true;
        }
};
