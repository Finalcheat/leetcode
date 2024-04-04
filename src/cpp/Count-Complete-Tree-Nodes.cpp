/**
 * @file Count-Complete-Tree-Nodes.cpp
 * @brief 完全二叉树的节点个数(https://leetcode.com/problems/count-complete-tree-nodes/description/)
 * @author Finalcheat
 * @date 2024-04-04
 */


/**
 *  二叉树递归遍历统计即可
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        int countNodes(TreeNode* root) {
            if (!root) {
                return 0;
            }
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
};
