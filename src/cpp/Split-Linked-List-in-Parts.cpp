/**
 * @file Split-Linked-List-in-Parts.cpp
 * @brief 拆分链表(https://leetcode.com/problems/split-linked-list-in-parts/description/)
 * @author Finalcheat
 * @date 2018-03-21
 */

/**
 * Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".
 * The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.
 * The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.
 * Return a List of ListNode's representing the linked list parts that are formed.
 * Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
 * Example 1:
 * Input:
 * root = [1, 2, 3], k = 5
 * Output: [[1],[2],[3],[],[]]
 * Explanation:
 * The input and each element of the output are ListNodes, not arrays.
 * For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
 * The first element output[0] has output[0].val = 1, output[0].next = null.
 * The last element output[4] is null, but it's string representation as a ListNode is [].
 * Example 2:
 * Input:
 * root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
 * Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
 * Explanation:
 * The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
 */

/**
 * 首先计算出拆分成k部分每部分至少的个数，然后取余算出需要补正的个数，最后遍历调整指针指向即可。
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
        vector<ListNode*> splitListToParts(ListNode* root, int k) {
            assert(k > 0);
            size_t count = 0;
            ListNode* node = root;
            for (; node != NULL; node = node->next) {
                ++count;
            }
            size_t remainder = count % k;
            size_t perCount = count / k;
            node = root;
            vector<ListNode*> result;
            for (int i = 0; i < k; ++i) {
                result.push_back(node);
                ListNode* perNode = node;
                size_t levelCount = perCount;
                if (remainder > 0) {
                    --remainder;
                    ++levelCount;
                }
                for (size_t j = 0; j < levelCount; ++j) {
                    perNode = node;
                    node = node->next;
                }
                if (perNode) {
                    perNode->next = NULL;
                }
            }
            return result;
        }
};
