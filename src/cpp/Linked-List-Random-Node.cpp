/**
 * @file Linked-List-Random-Node.cpp
 * @brief 链表随机节点(https://leetcode.com/problems/linked-list-random-node/description/)
 * @author Finalcheat
 * @date 2018-06-01
 */

/**
 * Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
 * Example:
 * // Init a singly linked list [1,2,3].
 * ListNode head = new ListNode(1);
 * head.next = new ListNode(2);
 * head.next.next = new ListNode(3);
 * Solution solution = new Solution(head);
 * // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
 * solution.getRandom();
 */


/**
 * 记录链表长度，然后随机一个数在长度范围内取就可以了。
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
        /** @param head The linked list's head.
            Note that the head is guaranteed to be not null, so it contains at least one node. */
        Solution(ListNode* head) {
            _len = 0;
            _head = head;
            ListNode* node = head;
            while (node) {
                ++_len;
                node = node->next;
            }
        }
        /** Returns a random node's value. */
        int getRandom() {
            std::random_device rd;
            int idx = rd() % _len;
            ListNode* node = _head;
            assert(node != NULL);
            while (idx--) {
                node = node->next;
            }
            return node->val;
        }
    private:
        size_t _len;
        ListNode* _head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
