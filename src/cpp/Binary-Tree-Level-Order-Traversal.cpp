/**
 * @file Binary-Tree-Level-Order-Traversal.cpp
 * @brief 二叉树的层序遍历(https://leetcode.com/problems/binary-tree-level-order-traversal/)
 * @author Finalcheat
 * @date 2016-03-22
 */

/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 */

/**
 * 使用队列作为辅助结构，在循环中将每一层的节点加入到队列中，下一次循环处理上一层的节点。
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
        vector<vector<int>> levelOrder(TreeNode* root) {
            if (root == NULL) {
                return vector<vector<int>>();
            }
            std::queue<TreeNode*> q;
            q.push(root);
            vector<vector<int>> result;
            while (!q.empty()) {
                const size_t levelLen = q.size();
                vector<int> level(levelLen);
                for (size_t i = 0; i < levelLen; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                    level[i] = node->val;
                }
                result.push_back(level);
            }
            return result;
        }
};
