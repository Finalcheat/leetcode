/**
 * @file Remove-Duplicates-from-Sorted-List-II.cpp
 * @brief 已排序链表删除重复元素II(https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)
 * @author Finalcheat
 * @date 2016-06-06
 */

/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */

/**
 * 遍历链表找到不重复元素链接在一起即可，问题出在查找重复元素这一步需要考虑各种边界条件(首尾)。
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
            ListNode* newHead = NULL;
            ListNode* newTail = NULL;
            ListNode* node = head;
            while (node) {
                ListNode* nextNode = node->next;
                if (nextNode && nextNode->val == node->val) {
                    while (nextNode->next && nextNode->next->val == nextNode->val) {
                        nextNode = nextNode->next;
                    }
                    node = nextNode->next;
                    if (!node && newTail) {
                        newTail->next = NULL;
                    }
                } else {
                    if (newTail) {
                        newTail->next = node;
                        newTail = node;
                    } else {
                        newHead = node;
                        newTail = node;
                    }
                    node = node->next;
                }
            }
            return newHead;
        }
};
