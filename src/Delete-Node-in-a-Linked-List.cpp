/**
 * @file Delete-Node-in-a-Linked-List.cpp
 * @brief 删除单链表节点(https://leetcode.com/problems/delete-node-in-a-linked-list/)
 * @author Finalcheat
 * @date 2016-03-07
 */

/**
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 */

/**
 * 删除单链表节点，一般的做法是从链表头节点开始遍历找到要删除节点的前一个节点，然后调节链表节点的指针即可，
 * 但是题中只给出要删除的节点，并未给出链表的头节点；此时可以换一种思路，把要删除的节点的下一个节点的值拷贝过来，
 * 同时删除下一个节点，造成删除了当前节点的假象(其实删除的是下一个节点)，但是此方法不能删除当前节点是链表最后一个节点这种情况，
 * 恰好题目要求也是除了最后一个节点。
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
        void deleteNode(ListNode* node) {
            if (node == NULL) {
                return;
            }
            ListNode* nextNode = node->next;
            if (nextNode) {
                node->val = nextNode->val;
                node->next = nextNode->next;
                delete nextNode;
            }
        }
};
