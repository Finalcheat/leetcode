/**
 * @file Remove-Linked-List-Elements.cpp
 * @brief 删除指定元素的链表节点(https://leetcode.com/problems/remove-linked-list-elements/)
 * @author Finalcheat
 * @date 2016-04-07
 */

/**
 * Remove all elements from a linked list of integers that have value val.
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 */

/**
 * 遍历的过程中删除节点，注意被删除的节点是头节点的情况。
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
        ListNode* removeElements(ListNode* head, int val) {
            while (head && head->val == val) {
                ListNode* node = head->next;
                head->next = NULL;
                delete head;
                head = node;
            }
            ListNode* newHead = head;
            while (head) {
                ListNode* nextNode = head->next;
                if (nextNode && nextNode->val == val) {
                    head->next = nextNode->next;
                    delete nextNode;
                } else {
                    head = nextNode;
                }
            }
            return newHead;
        }
};
