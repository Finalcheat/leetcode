/**
 * @file Merge-Nodes-In-Between-Zeros.cpp
 * @brief 合并零之间的节点(https://leetcode.com/problems/merge-nodes-in-between-zeros/description/)
 * @author Finalcheat
 * @date 2024-08-10
 */

/**
 * 循环中判断非零节点累加。
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* mergeNodes(ListNode* head) {
            ListNode* dummy = new ListNode();
            ListNode* prev = dummy;
            ListNode* ptr = head;
            while (ptr != nullptr) {
                if (ptr->val != 0) {
                    prev->next = new ListNode(ptr->val);
                    prev = prev->next;
                    while (ptr->next != nullptr && ptr->next->val != 0) {
                        ptr = ptr->next;
                        prev->val += ptr->val;
                    }
                }
                ptr = ptr->next;
            }
            ptr = dummy->next;
            delete dummy;
            return ptr;
        }
};
