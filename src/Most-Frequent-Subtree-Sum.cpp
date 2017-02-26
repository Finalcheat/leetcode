/**
 * @file Most-Frequent-Subtree-Sum.cpp
 * @brief 最频繁出现的子树节点和(https://leetcode.com/problems/most-frequent-subtree-sum)
 * @author Finalcheat
 * @date 2017-02-26
 */

/**
 * Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.
 * Examples 1
 * Input:
 *   5
 *  /  \
 * 2   -3
 * return [2, -3, 4], since all the values happen only once, return all of them in any order.
 * Examples 2
 * Input:
 *   5
 *  /  \
 * 2   -5
 * return [2], since 2 happens twice, however -5 only occur once.
 * Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
 */

/**
 * 将子树节点和用hashtable记录相应的次数，最后遍历找出出现次数最多的值即可。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<int> findFrequentTreeSum(TreeNode* root) {
            std::unordered_map<int, int> u;
            subTreeSum(root, u);
            int frequentSumCount = 0;
            for (std::unordered_map<int, int>::const_iterator it = u.begin(); it != u.end(); ++it) {
                if (it->second > frequentSumCount) {
                    frequentSumCount = it->second;
                }
            }
            vector<int> result;
            for (std::unordered_map<int, int>::const_iterator it = u.begin(); it != u.end(); ++it) {
                if (it->second == frequentSumCount) {
                    result.push_back(it->first);
                }
            }
            return result;
        }
    private:
        int subTreeSum(TreeNode* node, std::unordered_map<int, int> &u) {
            if (node) {
                int val = node->val + subTreeSum(node->left, u) + subTreeSum(node->right, u);
                ++u[val];
                return val;
            }
            return 0;
        }
};
