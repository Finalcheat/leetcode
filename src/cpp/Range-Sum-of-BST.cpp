/**
 * @file Range-Sum-of-BST.cpp
 * @brief 二叉搜索树的范围和(https://leetcode.com/problems/range-sum-of-bst)
 * @author Finalcheat
 * @date 2018-12-06
 */

/**
 * Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
 * The binary search tree is guaranteed to have unique values.
 * Example 1:
 * Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
 * Output: 32
 * Example 2:
 * Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
 * Output: 23
 */

/**
 * 中序遍历即可。
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
        Solution() : sum(0) {
        }
    public:
        int rangeSumBST(TreeNode* root, int L, int R) {
            if (!root) {
                return sum;
            }
            const int val = root->val;
            if (val >= L) {
                rangeSumBST(root->left, L, R);
            }

            if (val <= R) {
                rangeSumBST(root->right, L, R);
            }

            if (val >= L && val <= R) {
                sum += val;
            }
            return sum;
        }
    private:
        int sum;
};
