/**
 * @file Longest-Univalue-Path.cpp
 * @brief 最长相同值路径(https://leetcode.com/problems/longest-univalue-path/description/)
 * @author Finalcheat
 * @date 2018-03-17
 */

/**
 * Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
 * Note: The length of path between two nodes is represented by the number of edges between them.
 * Example 1:
 * Input:
 *               5
 *              / \
 *             4   5
 *            / \   \
 *           1   1   5
 * Output:
 * 2
 * Example 2:
 * Input:
 *               1
 *              / \
 *             4   5
 *            / \   \
 *           4   4   5
 * Output:
 * 2
 */

/**
 * 递归解决，找出左右子树最长相同值，跟当前节点最长相同值对比，取最大即可。
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
        int longestUnivaluePath(TreeNode* root) {
            if (!root) {
                return 0;
            }
            int childMax = std::max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
            return std::max(childMax, _longestUnivaluePath(root->left, root->val) +
                            _longestUnivaluePath(root->right, root->val));
        }
    private:
        int _longestUnivaluePath(TreeNode* node, const int parentValue) {
            if (!node) {
                return 0;
            }
            if (node->val != parentValue) {
                return 0;
            }
            return (1 + std::max(_longestUnivaluePath(node->left, parentValue),
                                 _longestUnivaluePath(node->right, parentValue)));
        }
};
