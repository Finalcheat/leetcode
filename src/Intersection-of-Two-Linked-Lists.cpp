/**
 * @file Intersection-of-Two-Linked-Lists.cpp
 * @brief 两个链表的交点(https://leetcode.com/problems/intersection-of-two-linked-lists/)
 * @author Finalcheat
 * @date 2016-03-23
 */

/**
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * For example, the following two linked lists:
 * A:          a1 → a2
 *                    ↘
 *                      c1 → c2 → c3
 *                    ↗  
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 * Notes:
 * - If the two linked lists have no intersection at all, return null.
 * - The linked lists must retain their original structure after the function returns.
 * - You may assume there are no cycles anywhere in the entire linked structure.
 * - Your code should preferably run in O(n) time and use only O(1) memory.
 */

/**
 * 首先算出两个链表的长度，然后得出链表的长度差n，使较长的链表先走n步，然后遍历两个链表即可。
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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* node = headA;
            size_t aLen = 0;
            while (node) {
                ++aLen;
                node = node->next;
            }
            
            node = headB;
            size_t bLen = 0;
            while (node) {
                ++bLen;
                node = node->next;
            }
            
            if (aLen > bLen) {
                int dis = aLen - bLen;
                while (dis > 0) {
                    headA = headA->next;
                    --dis;
                }
            } else {
                int dis = bLen - aLen;
                while (dis > 0) {
                    headB = headB->next;
                    --dis;
                }
            }
            
            while (headA && headB) {
                if (headA == headB) {
                    return headA;
                } else {
                    headA = headA->next;
                    headB = headB->next;
                }
            }
            return NULL;
        }
};
