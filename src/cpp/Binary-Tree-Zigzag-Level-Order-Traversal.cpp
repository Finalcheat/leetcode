/**
 * @file Binary-Tree-Zigzag-Level-Order-Traversal.cpp
 * @brief Binary Tree Zigzag Level Order Traversal(https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
 * @author Finalcheat
 * @date 2017-03-26
 */

/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */

/**
 * 基本上就是类似层序遍历，难点是方向会改变，用一个变量标记当前的方向，在每一层遍历后改变方向，配合栈输出结果即可。
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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if (root == NULL) {
                return vector<vector<int>>();
            }
            std::stack<TreeNode*> s;
            s.push(root);
            vector<vector<int>> result;
            int levelLen = 1;
            int direction = 1;
            while (!s.empty()) {
                vector<TreeNode*> v;
                while (levelLen--) {
                    TreeNode* node = s.top();
                    s.pop();
                    v.push_back(node);
                }
                vector<int> level(v.size());
                levelLen = 0;
                for (size_t i = 0; i < v.size(); ++i) {
                    TreeNode* node = v[i];
                    level[i] = node->val;
                    if (direction == 1) {
                        // left to right
                        if (node->left) {
                            s.push(node->left);
                            ++levelLen;
                        }
                        if (node->right) {
                            s.push(node->right);
                            ++levelLen;
                        }
                    } else {
                        // right to left
                        if (node->right) {
                            s.push(node->right);
                            ++levelLen;
                        }
                        if (node->left) {
                            s.push(node->left);
                            ++levelLen;
                        }
                    }
                }
                direction = ~direction;
                result.push_back(level);
            }
            return result;
        }
};
