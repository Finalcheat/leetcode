/**
 * @file Maximum-Depth-Of-Binary-Tree.cpp
 * @brief 二叉树的最大深度(https://leetcode.com/problems/maximum-depth-of-binary-tree/)
 * @author Finalcheat
 * @date 2016-03-06
 */

/**
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

/**
 * 使用递归解法最简单，二叉树的最大深度等于1+左右子树中的最大深度
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
        int maxDepth(TreeNode* root) {
            if (root == NULL) {
                return 0;
            }
            return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
        }
};
