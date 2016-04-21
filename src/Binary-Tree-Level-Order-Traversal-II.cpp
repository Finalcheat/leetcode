/**
 * @file Binary-Tree-Level-Order-Traversal-II.cpp
 * @brief 二叉树层序遍历II(https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) 
 * @author Finalcheat
 * @date 2016-04-21
 */

/**
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 */

/**
 * 层序遍历，使用队列作为辅助结构，将每层的节点压入队列中，在循环中出队列即可，最后反转结果。
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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            if (!root) {
                return std::vector<std::vector<int>>();
            }
            std::vector<std::vector<int>> result;
            std::queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                const size_t levelLen = q.size();
                std::vector<int> levelVec(levelLen);
                for (size_t i = 0; i < levelLen; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                    levelVec[i] = node->val;
                }
                result.push_back(levelVec);
            }
            std::reverse(result.begin(), result.end());
            return result;
        }
};
