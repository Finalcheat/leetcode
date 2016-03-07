/**
 * @file Same-Tree.cpp
 * @brief 判断二叉树是否相同(https://leetcode.com/problems/same-tree/)
 * @author Finalcheat
 * @date 2016-03-07
 */

/**
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

/**
 * 判断当前节点值是否相等，若相等则递归调用左右子树。
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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (p == NULL && p == q) {
                return true;
            }
            if (p && q) {
                if (p->val != q->val) {
                    return false;
                } else {
                    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
                }
            } else {
                return false;
            }
        }
};
