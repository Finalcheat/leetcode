/**
 * @file Merge-k-Sorted-Lists.cpp.cpp
 * @brief 合并k个已排序的链表(https://leetcode.com/problems/merge-k-sorted-lists/)
 * @author Finalcheat
 * @date 2017-04-04
 */

/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

/**
 * 每次循环从k个链表中取出一项，选出最小的元素同时链表向前走一步。
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
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode* head = NULL;
            ListNode* tail = NULL;
            while (true) {
                int minValue = -1;
                int minValueIndex = -1;
                for (size_t i = 0; i < lists.size(); ++i) {
                    if (minValueIndex == -1) {
                        if (lists[i]) {
                            minValue = lists[i]->val;
                            minValueIndex = i;
                        }
                    } else {
                        if (lists[i] && lists[i]->val < minValue) {
                            minValue = lists[i]->val;
                            minValueIndex = i;
                        }
                    }
                }
                if (minValueIndex == -1) {
                    break;
                } else {
                    if (tail) {
                        tail->next = new ListNode(minValue);
                        tail = tail->next;
                    } else {
                        head = tail = new ListNode(minValue);
                    }
                    lists[minValueIndex] = lists[minValueIndex]->next;
                }
            }
            return head;
        }
};
