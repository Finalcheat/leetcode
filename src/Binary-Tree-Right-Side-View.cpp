/**
 * @file Binary-Tree-Right-Side-View.cpp
 * @brief 二叉树的右侧视图(https://leetcode.com/problems/binary-tree-right-side-view/) 
 * @author Finalcheat
 * @date 2016-04-23
 */

/**
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 * For example:
 * Given the following binary tree,
 *    1            <---
 *  /   \
 * 2     3         <---
 *  \     \
 *   5     4       <---
 * You should return [1, 3, 4].
 */

/**
 * 使用层序遍历的方法，在循环中取出每一层的右侧视图节点，而每一层的右侧视图节点是当前节点为右子树节点优先，否则取左子树节点。
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
        vector<int> rightSideView(TreeNode* root) {
            if (!root) {
                return std::vector<int>();
            }
            std::queue<TreeNode*> q;
            q.push(root);
            std::vector<int> result;
            result.push_back(root->val);
            while (!q.empty()) {
                int levelLen = q.size();
                int levelFind = false;
                while (levelLen--) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->right) {
                        q.push(node->right);
                        if (!levelFind) {
                            result.push_back(node->right->val);
                            levelFind = true;
                        }
                    }
                    if (node->left) {
                        q.push(node->left);
                        if (!levelFind) {
                            result.push_back(node->left->val);
                            levelFind = true;
                        }
                    }
                }
            }
            return result;
        }
};
