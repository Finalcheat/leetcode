/**
 * @file Rotate-List.cpp
 * @brief 旋转单链表(https://leetcode.com/problems/rotate-list/)
 * @author Finalcheat
 * @date 2016-03-26
 */

/**
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */

/**
 * 用两个指针，使它们的位置分别指向到旋转点的末尾，最后调整指针指向即可，需要注意的是各种边界条件的考虑。
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
        ListNode* rotateRight(ListNode* head, int k) {
            if (head == NULL) {
                return head;
            }
            int len = listLen(head);
            k = k % len;
            if (k == 0) {
                return head;
            }
            ListNode* node2 = head;
            while (k-- && node2) {
                node2 = node2->next;
            }
            ListNode* node1 = head;
            while (node2 && node2->next) {
                node1 = node1->next;
                node2 = node2->next;
            }
            ListNode* newHead = NULL;
            if (node2 == NULL || node2 == head) {
                newHead = head;
            } else {
                newHead = node1->next;
                node2->next = head;
                node1->next = NULL;
            }
            return newHead;
        }

    private:
        int listLen(ListNode* head) {
            int length = 0;
            while (head) {
                ++length;
                head = head->next;
            }
            return length;
        }
};
