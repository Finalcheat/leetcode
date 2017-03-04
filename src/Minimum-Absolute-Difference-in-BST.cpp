/**
 * @file Minimum-Absolute-Difference-in-BST.cpp
 * @brief 二叉排序树最小的绝对差(https://leetcode.com/problems/minimum-absolute-difference-in-bst/)
 * @author Finalcheat
 * @date 2017-03-04
 */

/**
 * Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
 * Example:
 * Input:
 *    1
 *     \
 *      3
 *     /
 *    2
 * Output:
 * 1
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 * Note: There are at least two nodes in this BST.
 */

/**
 * BST使用中序遍历得到升序排序，而最小的绝对差肯定是发生在两个相邻数字，所以只要遍历过程相减并且对比最小值即可。
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
        int getMinimumDifference(TreeNode* root) {
            int min = INT_MAX;
            int prev = -1;
            searchBSTTree(root, min, prev);
            return min;
        }
    protected:
        void searchBSTTree(TreeNode* node, int& min, int& prev) {
            if (!node) {
                return;
            }
            searchBSTTree(node->left, min, prev);
            int dif = prev != -1 ? node->val - prev : INT_MAX;
            min = std::min(min, dif);
            prev = node->val;
            searchBSTTree(node->right, min, prev);
        }
};
