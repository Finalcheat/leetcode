/**
 * @file Merge-Two-Sorted-Lists.cpp
 * @brief 合并两个已排序的链表(https://leetcode.com/problems/merge-two-sorted-lists/)
 * @author Finalcheat
 * @date 2016-03-15
 */

/**
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

/**
 * 同时遍历两个链表，对两个节点进行比较，较小的节点加入到新建表中同时向前走一步。
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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* newListHead = NULL;
            ListNode* currentNode = NULL;
            while (l1 && l2) {
                ListNode* node = NULL;
                if (l1->val < l2->val) {
                    node = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    node = new ListNode(l2->val);
                    l2 = l2->next;
                }
                if (newListHead == NULL) {
                    newListHead = currentNode = node;
                } else {
                    currentNode->next = node;
                    currentNode = node;
                }
            }
            while (l1) {
                ListNode* node = new ListNode(l1->val);
                l1 = l1->next;
                if (newListHead == NULL) {
                    newListHead = currentNode = node;
                } else {
                    currentNode->next = node;
                    currentNode = node;
                }
            }
            while (l2) {
                ListNode* node = new ListNode(l2->val);
                l2 = l2->next;
                if (newListHead == NULL) {
                    newListHead = currentNode = node;
                } else {
                    currentNode->next = node;
                    currentNode = node;
                }
            }
            return newListHead;
        }
};
