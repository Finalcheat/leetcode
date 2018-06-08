/**
 * @file Reverse-Linked-List-II.cpp
 * @brief 反转链表II(https://leetcode.com/problems/reverse-linked-list-ii/)
 * @author Finalcheat
 * @date 2016-06-07
 */

/**
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */

/**
 * 将指定的部分按照Reverse Linked List题目的方法反转即可，需要注意的是首尾部分的处理。
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
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            const int diff = n - m;
            if (diff <= 0) {
                return head;
            }
            ListNode* node = head;
            ListNode* prevNode = nullptr;
            int count = 1;
            while (count < m && node) {
                prevNode = node;
                node = node->next;
                ++count;
            }
            count = 0;
            ListNode* currentNode = NULL;
            ListNode* nextNode = NULL;
            while (node && count <= diff) {
                nextNode = node->next;
                node->next = currentNode;
                currentNode = node;
                node = nextNode;
                ++count;
            }
            if (prevNode) {
                if (prevNode->next) {
                    prevNode->next->next = nextNode;
                }
                prevNode->next = currentNode;
            } else {
                if (head) {
                    head->next = nextNode;
                }
                head = currentNode;
            }
            return head;
        }
};
