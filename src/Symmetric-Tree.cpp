/**
 * @file Symmetric-Tree.cpp
 * @brief 判断二叉树是否对称(https://leetcode.com/problems/symmetric-tree/)
 * @author Finalcheat
 * @date 2016-03-20
 */

/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 */

/**
 * 递归解法。
 * 满足以下条件:
 * 1.当前两个节点值相等。
 * 2.左子树与右子树对称。
 * 3.右子树与左子树对称。
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
        bool isSymmetric(TreeNode* root) {
            if (root == NULL) {
                return true;
            } else {
                return isSymmetric(root->left, root->right);
            }
        }
        
    private:
        bool isSymmetric(TreeNode* left, TreeNode* right) {
            if (left == NULL) {
                return right == NULL;
            } else if (right == NULL) {
                return false;
            }
            if (left->val != right->val) {
                return false;
            } else {
                return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
            }
        }
};
