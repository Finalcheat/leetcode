/**
 * @file Balanced-Binary-Tree.cpp
 * @brief 判断二叉树是否平衡(https://leetcode.com/problems/balanced-binary-tree/) 
 * @author Finalcheat
 * @date 2016-03-27
 */

/**
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

/**
 * 递归解法。判断当前节点左右子树的深度相差是否大于1，若大于1表示不平衡，否则递归调用左右子树。
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
        bool isBalanced(TreeNode* root) {
            if (root == NULL) {
                return true;
            }
            int leftDepth = depth(root->left);
            int rightDepth = depth(root->right);
            const int dif = leftDepth - rightDepth;
            if (dif > 1 || dif < -1) {
                return false;
            }
            return isBalanced(root->left) && isBalanced(root->right);
        }

    private:
        int depth(TreeNode* node) {
            if (node == NULL) {
                return 0;
            }
            return 1 + std::max(depth(node->left), depth(node->right));
        }
};
