/**
 * @file Add-Two-Numbers-II.cpp
 * @brief 两个数相加II(https://leetcode.com/problems/add-two-numbers-ii/)
 * @author Finalcheat
 * @date 2017-03-04
 */

/**
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 * Example:
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 */

/**
 * 题目要求不能修改原链表，也就是不能反转链表进行相加，数相加一般的方法是从低位开始相加一直到高位，也就是说低位要先处理，所以用栈的先进后出的特性。
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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            std::stack<int> s1;
            std::stack<int> s2;
            while (l1) {
                s1.push(l1->val);
                l1 = l1->next;
            }
            while (l2) {
                s2.push(l2->val);
                l2 = l2->next;
            }
            ListNode* prev = NULL;
            ListNode* node = NULL;
            int carry = 0;
            while (!s1.empty() || !s2.empty() || carry) {
                int num1 = 0;
                if (!s1.empty()) {
                    num1 = s1.top();
                    s1.pop();
                }
                int num2 = 0;
                if (!s2.empty()) {
                    num2 = s2.top();
                    s2.pop();
                }
                int sum = num1 + num2 + carry;
                carry = sum / 10;
                sum = sum % 10;
                node = new ListNode(sum);
                node->next = prev;
                prev = node;
            }
            return node;
        }
};
