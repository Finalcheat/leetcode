/**
 * @file Remove-Duplicates-from-Sorted-List.cpp
 * @brief 已排序的链表中删除重复的节点(https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
 * @author Finalcheat
 * @date 2016-03-09
 */

/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

/**
 * 遍历链表，比较前后节点的值是否相同，相同的话删除同时调节链表指针指向。
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
        ListNode* deleteDuplicates(ListNode* head) {
            if (!head) {
                return NULL;
            }
            ListNode* l = head;
            ListNode* node = head;
            while (node) {
                ListNode* nextNode = node->next;
                if (!nextNode) {
                    break;
                }
                if (node->val == nextNode->val) {
                    // delete
                    node->next = nextNode->next;
                    delete nextNode;
                } else {
                    node = nextNode;
                }
            }
            return l;
        }
};
