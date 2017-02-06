/**
 * @file Sum-of-Left-Leaves.cpp
 * @brief 二叉树左子叶节点的和(https://leetcode.com/problems/sum-of-left-leaves/)
 * @author Finalcheat
 * @date 2017-02-06
 */

/**
 * Find the sum of all left leaves in a given binary tree.
 * Example:
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 */

/**
 * 遍历二叉树过程中判断节点是否是左节点而且是叶节点，是则把节点的值累加即可。
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
        int sumOfLeftLeaves(TreeNode* root) {
            if (root == NULL) {
                return 0;
            }
            int sum = 0;
            _sumOfLeftLeaves(root, sum);
            return sum;
        }

    private:
        // 递归遍历二叉树
        void _sumOfLeftLeaves(TreeNode* node, int& sum) {
            if (node->left) {
                sum += _isLeftLeavesAndVal(node->left, node);
                _sumOfLeftLeaves(node->left, sum);
            }
            if (node->right) {
                _sumOfLeftLeaves(node->right, sum);
            }
        }

        // 判断是否是左叶节点，是则返回节点的值，否则返回0
        int _isLeftLeavesAndVal(TreeNode* node, TreeNode* parentNode) {
            if (node->left == NULL && node->right == NULL && parentNode->left == node) {
                return node->val;
            }
            return 0;
        }

};
