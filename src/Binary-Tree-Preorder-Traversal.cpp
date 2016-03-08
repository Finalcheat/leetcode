/**
 * @file Binary-Tree-Preorder-Traversal.cpp
 * @brief 二叉树非递归前序遍历(https://leetcode.com/problems/binary-tree-preorder-traversal/)
 * @author Finalcheat
 * @date 2016-03-08
 */

/**
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * For example:
 * Given binary tree {1,#,2,3},
 * return [1,2,3].
 */

/**
 * 要求不能用递归，可以使用栈作为辅助，将左右子树压入栈中即可。
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
        vector<int> preorderTraversal(TreeNode* root) {
            if (root == NULL) {
                return vector<int>();
            }
            std::stack<TreeNode*> s;
            s.push(root);
            std::vector<int> result;
            while (!s.empty()) {
                TreeNode * node = s.top();
                s.pop();
                result.push_back(node->val);
                if (node->right) {
                    s.push(node->right);
                }
                if (node->left) {
                    s.push(node->left);
                }
            }
            return result;
        }
};
