/**
 * @file Find-Bottom-Left-Tree-Value.cpp
 * @brief 查找底部最左边树节点的值(https://leetcode.com/problems/next-greater-element-i/)
 * @author Finalcheat
 * @date 2017-02-22
 */

/**
 * Given a binary tree, find the leftmost value in the last row of the tree.
 * Example 1:
 * Input:
 *     2
 *    / \
 *   1   3
 * Output:
 * 1
 * Example 2:
 * Input:
 *         1
 *        / \
 *       2   3
 *      /   / \
 *     4   5   6
 *        /
 *       7
 * Output:
 * 7
 */

/**
 * 使用层序遍历的方法找最左边的树节点。
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
        int findBottomLeftValue(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);
            TreeNode* result;
            while (!q.empty()) {
                result = q.front();
                const size_t levelLen = q.size();
                for (size_t i = 0; i < levelLen; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }
            return result->val;
        }
};
