/**
 * @file Path-Sum-III.cpp
 * @brief 路径总和III(https://leetcode.com/problems/path-sum-iii/description/)
 * @author Finalcheat
 * @date 2018-08-24
 */

/**
 * You are given a binary tree in which each node contains an integer value.
 * Find the number of paths that sum to a given value.
 * The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
 * The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
 * Example:
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *       10
 *      /  \
 *     5   -3
 *    / \    \
 *   3   2   11
 *  / \   \
 * 3  -2   1
 * Return 3. The paths that sum to 8 are:
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 */

/**
 * 递归解决即可。
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
        int pathSum(TreeNode* root, int sum) {
            int count = 0;
            if (!root) {
                return count;
            }
            _pathSum(root, sum, count);
            return count + pathSum(root->left, sum) + pathSum(root->right, sum);
        }
    private:
        void _pathSum(TreeNode* node, int sum, int& count) {
            if (!node) {
                return;
            }
            if (node->val == sum) {
                ++count;
            }
            sum -= node->val;
            _pathSum(node->left, sum, count);
            _pathSum(node->right, sum, count);
        }
};
