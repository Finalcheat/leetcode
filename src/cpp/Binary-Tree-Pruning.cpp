/**
 * @file Binary-Tree-Pruning.cpp
 * @brief 二叉树修剪(https://leetcode.com/problems/binary-tree-pruning/description/)
 * @author Finalcheat
 * @date 2018-07-24
 */

/**
 * We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.
 * Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
 * (Recall that the subtree of a node X is X, plus every node that is a descendant of X.)
 * Example 1:
 * Input: [1,null,0,0,1]
 * Output: [1,null,0,null,1]
 * Explanation:
 * Only the red nodes satisfy the property "every subtree not containing a 1".
 * The diagram on the right represents the answer.
 * Example 2:
 * Input: [1,0,1,0,0,0,1]
 * Output: [1,null,1,null,1]
 * Example 3:
 * Input: [1,1,0,1,1,0,1,0]
 * Output: [1,1,0,1,1,null,1]
 */

/**
 * 递归解法，判断左右子树是否包含1，如果是，置为NULL，否则递归调用左右子树。
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
        TreeNode* pruneTree(TreeNode* root) {
            if (!root) {
                return NULL;
            }
            if (isContainingOne(root->left)) {
                pruneTree(root->left);
            } else {
                root->left = NULL;
            }
            if (isContainingOne(root->right)) {
                pruneTree(root->right);
            } else {
                root->right = NULL;
            }
            return root;
        }
    private:
        bool isContainingOne(TreeNode* node) {
            if (!node) {
                return false;
            }
            if (node->val == 1) {
                return true;
            }
            bool left = isContainingOne(node->left);
            if (left) {
                return true;
            }
            return isContainingOne(node->right);
        }
};
