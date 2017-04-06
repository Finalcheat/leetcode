/**
 * @file Reorder-List.cpp
 * @brief Reorder List(https://leetcode.com/problems/reorder-list/)
 * @author Finalcheat
 * @date 2017-04-06
 */

/**
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * You must do this in-place without altering the nodes' values.
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

/**
 * 将链表节点压入栈中并计算长度，调整链表节点指针只有后半部节点，所以只需要循环长度的一半调整指针指向即可。
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
        void reorderList(ListNode* head) {
            std::stack<ListNode*> s;
            ListNode* node = head;
            int len = 0;
            while (node) {
                s.push(node);
                ++len;
                node = node->next;
            }
            
            node = head;
            int halfLen = len / 2;
            while (halfLen-- > 0) {
                ListNode* top = s.top();
                s.pop();
                
                top->next = node->next;
                node->next = top;
                node = top->next;
            }
            if (node) {
                node->next = NULL;
            }
        }
};
