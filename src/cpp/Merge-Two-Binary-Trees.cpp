/**
 * @file Merge-Two-Binary-Trees.cpp
 * @brief 合并二叉树(https://leetcode.com/problems/merge-two-binary-trees/)
 * @author Finalcheat
 * @date 2017-06-20
 */

/**
 * Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
 * You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
 */

/**
 * 递归解决即可。
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
        TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
            if (t1 == NULL) {
                return t2;
            } else if (t2 == NULL) {
                return t1;
            }
            
            TreeNode* node = new TreeNode(t1->val + t2->val);
            node->left = mergeTrees(t1->left, t2->left);
            node->right = mergeTrees(t1->right, t2->right);
            return node;
        }
};
