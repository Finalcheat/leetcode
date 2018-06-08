/**
 * @file Add-Two-Numbers.cpp
 * @brief 链表表示的两个数相加(https://leetcode.com/problems/add-two-numbers/)
 * @author Finalcheat
 * @date 2017-03-31
 */

/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

/**
 * 遍历链表相加处理进位即可，注意最高位相加结果可能进位的情况。
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
            int carry = 0;
            ListNode* head = NULL;
            ListNode* end = NULL;
            while (l1 || l2) {
                int n1 = 0;
                if (l1) {
                    n1 = l1->val;
                    l1 = l1->next;
                }
                
                int n2 = 0;
                if (l2) {
                    n2 = l2->val;
                    l2 = l2->next;
                }
                
                int sum = n1 + n2 + carry;
                carry = sum / 10;
                sum = sum % 10;
                
                if (head) {
                    end->next = new ListNode(sum);
                    end = end->next;
                } else {
                    head = new ListNode(sum);
                    end = head;
                }
            }
            if (carry != 0) {
                end->next = new ListNode(carry);
                end = end->next;
            }
            return head;
        }
};
