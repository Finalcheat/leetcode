/**
 * @file Middle-of-the-Linked-List.cpp
 * @brief 单链表中间节点(https://leetcode.com/problems/middle-of-the-linked-list/description/)
 * @author Finalcheat
 * @date 2018-08-01
 */

/**
 * Given a non-empty, singly linked list with head node head, return a middle node of linked list.
 * If there are two middle nodes, return the second middle node.
 * Example 1:
 * Input: [1,2,3,4,5]
 * Output: Node 3 from this list (Serialization: [3,4,5])
 * The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
 * Note that we returned a ListNode object ans, such that:
 * ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
 * Example 2:
 * Input: [1,2,3,4,5,6]
 * Output: Node 4 from this list (Serialization: [4,5,6])
 * Since the list has two middle nodes with values 3 and 4, we return the second one.
 */

/**
 * 首先遍历单链表得到长度，然后从头结点开始前进长度的一半即可。
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
        ListNode* middleNode(ListNode* head) {
            size_t len = 0;
            ListNode* p = head;
            while (p) {
                ++len;
                p = p->next;
            }
            int halfLen = len / 2;
            p = head;
            while (halfLen > 0) {
                p = p->next;
                --halfLen;
            }
            return p;
        }
};
