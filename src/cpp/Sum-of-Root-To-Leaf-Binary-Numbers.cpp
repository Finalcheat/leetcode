/**
 * @file Sum-of-Root-To-Leaf-Binary-Numbers.cpp
 * @brief 根到叶节点二进制数的和(https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)
 * @author Finalcheat
 * @date 2019-09-22
 */

/**
 * Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
 * For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
 * Return the sum of these numbers.
 * Example 1:
 * Input: [1,0,1,0,1,0,1]
 * Output: 22
 * Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
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
        int sumRootToLeaf(TreeNode* root) {
            int sum = 0;
            _sumRootToLeaf(root, sum, 0);
            return sum;
        }
    private:
        void _sumRootToLeaf(TreeNode* node, int& sum, int curVal) {
            if (!node) {
                return;
            }
            curVal = (curVal << 1) + node->val;
            if (node->left == NULL && node->right == NULL) {
                sum += curVal;
                return;
            }
            if (node->left) {
                _sumRootToLeaf(node->left, sum, curVal);
            }
            if (node->right) {
                _sumRootToLeaf(node->right, sum, curVal);
            }
        }
};
