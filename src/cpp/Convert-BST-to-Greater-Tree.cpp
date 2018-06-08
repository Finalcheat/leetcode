/**
 * @file Convert-BST-to-Greater-Tree.cpp
 * @brief 二叉搜索树转较大树(https://leetcode.com/problems/convert-bst-to-greater-tree/description/)
 * @author Finalcheat
 * @date 2018-01-09
 */

/**
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
 *
 * Example:
 * Input: The root of a Binary Search Tree like this:
 *               5
 *             /   \
 *            2     13
 *
 * Output: The root of a Greater Tree like this:
 *              18
 *             /   \
 *           20     13
 */

/**
 * 树遍历的变种，按右中左遍历，目的是算出比当前节点大的累加值。
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
        TreeNode* convertBST(TreeNode* root) {
            int sum = 0;
            convertBST(root, sum);
            return root;
        }

    private:
        void convertBST(TreeNode*& node, int& sum) {
            if (!node) {
                return;
            }
            convertBST(node->right, sum);
            node->val += sum;
            sum = node->val;
            convertBST(node->left, sum);
        }

};
