/**
 * @file Path-Sum-II.cpp
 * @brief 二叉树根到叶子节点的路径和(https://leetcode.com/problems/path-sum/) 
 * @author Finalcheat
 * @date 2016-04-26
 */


/**
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

/**
 * 递归解法，过程中减去当前节点的值并递归调用左右子树，最后把值相等的添加到结果。
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
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            std::vector<int> v;
            std::vector<std::vector<int>> result;
            _pathSum(root, sum, v, result);
            return result;
        }
        
    private:
        void _pathSum(TreeNode* node, int sum, std::vector<int> v, std::vector<std::vector<int>>& result) {
            if (!node) {
                return;
            }
            if (sum == node->val && (!node->left) && (!node->right)) {
                v.push_back(node->val);
                result.push_back(v);
                return;
            }
            v.push_back(node->val);
            if (node->left) {
                _pathSum(node->left, sum - node->val, v, result);
            }
            if (node->right) {
                _pathSum(node->right, sum - node->val, v, result);
            }
        }
};
