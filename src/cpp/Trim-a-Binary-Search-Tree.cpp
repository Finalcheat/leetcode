/**
 * @file Trim-a-Binary-Search-Tree.cpp
 * @brief 二叉搜索树修剪(https://leetcode.com/problems/trim-a-binary-search-tree/description/)
 * @author Finalcheat
 * @date 2018-03-11
 */

/**
 * Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.
 * Example 1:
 * Input:
 *     1
 *    / \
 *   0   2
 *
 *   L = 1
 *   R = 2
 *
 * Output:
 *     1
 *       \
 *        2
 *
 * Example 2:
 * Input:
 *     3
 *    / \
 *   0   4
 *    \
 *     2
 *    /
 *   1
 *
 *   L = 1
 *   R = 3
 *
 * Output:
 *       3
 *      /
 *    2
 *   /
 *  1
 */

/**
 * 二叉树的问题用递归解决比较好，将当前节点与L、R比较，小于L则说明结果在右子树，大于R则说明在左子树。
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
        TreeNode* trimBST(TreeNode* root, int L, int R) {
            if (!root) {
                return NULL;
            }
            if (root->val < L) {
                return trimBST(root->right, L, R);
            } else if (root->val > R) {
                return trimBST(root->left, L, R);
            }
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
};
