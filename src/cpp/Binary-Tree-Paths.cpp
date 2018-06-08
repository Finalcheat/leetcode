/**
 * @file Binary-Tree-Paths.cpp
 * @brief 二叉树路径(https://leetcode.com/problems/binary-tree-paths/) 
 * @author Finalcheat
 * @date 2016-04-20
 */

/**
 * Given a binary tree, return all root-to-leaf paths.
 * For example, given the following binary tree:
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 */

/**
 * 深度优先搜索遍历二叉树节点即可。
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
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> result;
            if (root) {
                _binaryTreePaths(root, "", result);
            }
            return result;
        }
        
    private:
        void _binaryTreePaths(TreeNode *root, string s, vector<string>& result) {
            s += std::to_string(root->val);
            if (!root->left && !root->right) {
                result.push_back(s);
            } else {
                if (root->left) {
                    _binaryTreePaths(root->left, s + "->", result);
                }
                if (root->right) {
                    _binaryTreePaths(root->right, s + "->", result);
                }
            }
        }
};
