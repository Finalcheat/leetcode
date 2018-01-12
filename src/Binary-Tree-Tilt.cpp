/**
 * @file Binary-Tree-Tilt.cpp
 * @brief 二叉树的坡度(https://leetcode.com/problems/binary-tree-tilt/description/)
 * @author Finalcheat
 * @date 2018-01-12
 */

/**
 * Given a binary tree, return the tilt of the whole tree.
 * The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
 * The tilt of the whole tree is defined as the sum of all nodes' tilt.
 * Example:
 * Input:
 *          1
 *        /   \
 *       2     3
 * Output: 1
 * Explanation:
 * Tilt of node 2 : 0
 * Tilt of node 3 : 0
 * Tilt of node 1 : |2-3| = 1
 * Tilt of binary tree : 0 + 0 + 1 = 1
 */

/**
 * 二叉树后序遍历即可。
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
        int findTilt(TreeNode* root) {
            int sum = 0;
            findTilt(root, sum);
            return sum;
        }

    private:
        int findTilt(const TreeNode* node, int& sum) {
            if (!node) {
                return 0;
            }
            const int left = findTilt(node->left, sum);
            const int right = findTilt(node->right, sum);
            sum += abs(left - right);
            return left + right + node->val;
        }

};
