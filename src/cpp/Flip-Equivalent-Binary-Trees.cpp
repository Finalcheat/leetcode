/**
 * @file Flip-Equivalent-Binary-Trees.cpp
 * @brief 反转等价二叉树(https://leetcode.com/problems/flip-equivalent-binary-trees/)
 * @author Finalcheat
 * @date 2019-03-13
 */

/**
 * For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.
 * A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
 * Write a function that determines whether two binary trees are flip equivalent.  The trees are given by root nodes root1 and root2.
 * Example 1:
 * Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
 * Output: true
 * Explanation: We flipped at nodes with values 1, 3, and 5.
 */

/**
 * 跟反转二叉树差不多，递归比较即可。
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
        bool flipEquiv(TreeNode* root1, TreeNode* root2) {
            if (!root1 && !root2) {
                return true;
            }
            if (root1 && root2 && root1->val == root2->val) {
                bool b1 = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
                bool b2 = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
                return b1 || b2;
            }
            return false;
        }
};
