/**
 * @file Linked-List-Cycle-II.cpp
 * @brief 判断链表中是否存在环II(https://leetcode.com/problems/linked-list-cycle-ii/)
 * @author Finalcheat
 * @date 2017-03-12
 */

/**
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Note: Do not modify the linked list.
 */

/**
 * 判断链表中是否有环，设定两个指针，一个指针每次走一步，另一个每次走两步，若存在环，则每次走两步的必然追上每次走一步的(多走了一圈)，最后将第一个指针从头与相遇的指针同时走，再次相遇的地方则是环开始的节点。
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
        ListNode *detectCycle(ListNode *head) {
            if (head == NULL) {
                return NULL;
            }
            ListNode* l1 = head;
            ListNode* l2 = head;
            while (1) {
                l1 = l1->next;
                if (!l1) {
                    return NULL;
                }
                l2 = l2->next;
                if (!l2) {
                    return NULL;
                }
                l2 = l2->next;
                if (!l2) {
                    return NULL;
                }
                if (l1 == l2) {
                    break;
                }
            }
            l1 = head;
            while (l1 != l2) {
                l1 = l1->next;
                l2 = l2->next;
            }
            return l1;
        }
};
