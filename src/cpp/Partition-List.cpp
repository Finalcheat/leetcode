/**
 * @file Partition-List.cpp
 * @brief 分隔链表(https://leetcode.com/problems/partition-list/description/)
 * @author Finalcheat
 * @date 2018-10-04
 */

/**
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * Example:
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 */

/**
 * 设成两段left和right，分别有head和tail指针，遍历过程中分别维护这两个指针即可，最后把left和right链接起来。
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
        ListNode* partition(ListNode* head, int x) {
            ListNode* leftHead = NULL;
            ListNode* leftTail = NULL;
            ListNode* rightHead = NULL;
            ListNode* rightTail = NULL;
            ListNode* node = head;
            while (node) {
                const int val = node->val;
                if (val < x) {
                    if (leftTail) {
                        leftTail->next = node;
                        leftTail = node;
                    } else {
                        leftHead = node;
                        leftTail = node;
                    }
                } else {
                    if (rightTail) {
                        rightTail->next = node;
                        rightTail = node;
                    } else {
                        rightHead = node;
                        rightTail = node;
                    }
                }
                node = node->next;
            }
            if (rightTail) {
                rightTail->next = NULL;
            }
            if (leftTail) {
                leftTail->next = rightHead;
            } else {
                leftHead = rightHead;
            }
            return leftHead;
        }
};
