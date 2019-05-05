/**
 * @file Next-Greater-Node-In-Linked-List.cpp
 * @brief 链表中的下一个比它大的节点(https://leetcode.com/problems/next-greater-node-in-linked-list/)
 * @author Finalcheat
 * @date 2019-03-31
 */

/**
 * We are given a linked list with head as the first node.  Let's number the nodes in the list: node_1, node_2, node_3, ... etc.
 * Each node may have a next larger value: for node_i, next_larger(node_i) is the node_j.val such that j > i, node_j.val > node_i.val, and j is the smallest possible choice.  If such a j does not exist, the next larger value is 0.
 * Return an array of integers answer, where answer[i] = next_larger(node_{i+1}).
 * Note that in the example inputs (not outputs) below, arrays such as [2,1,5] represent the serialization of a linked list with a head node value of 2, second node value of 1, and third node value of 5.
 * Example 1:
 * Input: [2,1,5]
 * Output: [5,5,0]
 * Example 2:
 * Input: [2,7,4,3,5]
 * Output: [7,0,5,5,0]
 * Example 3:
 * Input: [1,7,5,1,9,2,5,1]
 * Output: [7,9,9,9,0,5,0,0]
 */

/**
 * 用栈作辅助结构，入栈的时候记录节点的下标，出栈时往该位置写值即可。
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
    private:
        struct ListNodeInfo {
            ListNodeInfo(size_t _idx, ListNode* _node) : idx(_idx), node(_node) {}
            size_t idx;
            ListNode* node;
        };
    public:
        vector<int> nextLargerNodes(ListNode* head) {
            size_t len = 0;
            for (ListNode* node = head; node; node = node->next) {
                ++len;
            }

            vector<int> result(len, 0);
            std::stack<ListNodeInfo> s;
            size_t idx = 0;
            for (ListNode* node = head; node; node = node->next) {
                const int value = node->val;
                while (!s.empty() && s.top().node->val < value) {
                    result[s.top().idx] = value;
                    s.pop();
                }
                s.push(ListNodeInfo(idx, node));
                ++idx;
            }

            return result;
        }
};
