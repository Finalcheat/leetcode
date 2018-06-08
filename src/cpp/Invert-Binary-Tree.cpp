/**
 * @file Invert-Binary-Tree.cpp
 * @brief 反转二叉树(https://leetcode.com/problems/invert-binary-tree/)
 * @author Finalcheat
 * @date 2016-03-07
 */


/**
 * 将左右子树位置调换，然后对左右子树递归调用即可。
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
        TreeNode* invertTree(TreeNode* root) {
            if (root == NULL) {
                return NULL;
            }
            TreeNode* leftNode = root->left;
            TreeNode* rightNode = root->right;
            root->left = rightNode;
            root->right = leftNode;
            invertTree(leftNode);
            invertTree(rightNode);
            return root;
        }
};
