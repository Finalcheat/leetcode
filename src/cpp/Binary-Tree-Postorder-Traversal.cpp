/**
 * @file Binary-Tree-Postorder-Traversal.cpp
 * @brief 二叉树后序遍历(https://leetcode.com/problems/binary-tree-postorder-traversal/)
 * @author Finalcheat
 * @date 2016-04-25
 */

/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [3,2,1].
 */

/**
 * 递归解析即可，非递归解决比较绕。
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
        vector<int> postorderTraversal(TreeNode* root) {
            std::vector<int> result;
            _postorderTraversal(root, result);
            return result;
        }
    private:
        void _postorderTraversal(TreeNode* node, std::vector<int>& result) {
            if (!node) {
                return;
            }
            _postorderTraversal(node->left, result);
            _postorderTraversal(node->right, result);
            result.push_back(node->val);
        }
};

