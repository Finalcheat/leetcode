/**
 * @file Linked-List-Cycle.cpp
 * @brief 判断链表中是否存在环(https://leetcode.com/problems/linked-list-cycle/)
 * @author Finalcheat
 * @date 2016-03-08
 */

/**
 * Given a linked list, determine if it has a cycle in it.
 * Follow up:
 * Can you solve it without using extra space?
 */

/**
 * 判断链表中是否有环，设定两个指针，一个指针每次走一步，另一个每次走两步，若存在环，则每次走两步的必然追上每次走一步的(多走了一圈)。
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
        bool hasCycle(ListNode *head) {
            if (head == NULL) {
                return false;
            }
            ListNode* l1 = head;
            ListNode* l2 = head;
            while (1) {
                l1 = l1->next;
                if (!l1) {
                    return false;
                }
                l2 = l2->next;
                if (!l2) {
                    return false;
                }
                l2 = l2->next;
                if (!l2) {
                    return false;
                }
                if (l1 == l2) {
                    return true;
                }
            }
            return false;
        }
};
