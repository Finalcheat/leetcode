/**
 * @file Linked-List-Components.cpp
 * @brief 链表组件(https://leetcode.com/problems/linked-list-components/description/)
 * @author Finalcheat
 * @date 2018-06-16
 */

/**
 * We are given head, the head node of a linked list containing unique integer values.
 * We are also given the list G, a subset of the values in the linked list.
 * Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.
 * Example 1:
 * Input:
 * head: 0->1->2->3
 * G = [0, 1, 3]
 * Output: 2
 * Explanation:
 * 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
 * Example 2:
 * Input:
 * head: 0->1->2->3->4
 * G = [0, 3, 1, 4]
 * Output: 2
 * Explanation:
 * 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
 */

/**
 * 遍历链表，如果当前节点值在G中且当前节点下一节点值不在G中，则说明连通分量在这里中断了，结果数加1。
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
        int numComponents(ListNode* head, vector<int>& G) {
            std::unordered_set<int> s(G.begin(), G.end());
            size_t count = 0;
            for (ListNode* cur = head; cur; cur = cur->next) {
                std::unordered_set<int>::const_iterator iter = s.find(cur->val);
                if (iter != s.end()) {
                    const ListNode* next = cur->next;
                    if (next == NULL) {
                        ++count;
                    } else if (s.find(next->val) == s.end()) {
                        ++count;
                    }
                }
            }
            return count;
        }
};
