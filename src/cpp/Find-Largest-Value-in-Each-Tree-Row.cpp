/**
 * @file Find-Largest-value-in-Each-Tree-Row.cpp
 * @brief 寻找二叉树中每一层的最大值(https://leetcode.com/problems/find-largest-value-in-each-tree-row)
 * @author Finalcheat
 * @date 2017-02-28
 */

/**
 * You need to find the largest value in each row of a binary tree.
 * Example:
 * Input: 
 *           1
 *          / \
 *         3   2
 *        / \   \
 *       5   3   9
 * Output: [1, 3, 9]
 */

/**
 * 层序遍历过程中寻找最大值即可。
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
        vector<int> largestValues(TreeNode* root) {
            if (!root) {
                return vector<int>();
            }
            std::queue<TreeNode*> q;
            q.push(root);
            vector<int> result;
            while (!q.empty()) {
                const size_t levelLen = q.size();
                TreeNode* node = q.front();
                int levelMax = node->val;
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                for (size_t i = 1; i < levelLen; ++i) {
                    node = q.front();
                    q.pop();
                    if (node->val > levelMax) {
                        levelMax = node->val;
                    }
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
                result.push_back(levelMax);
            }
            return result;
        }
};
