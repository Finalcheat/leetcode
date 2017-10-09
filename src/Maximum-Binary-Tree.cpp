/**
 * @file Maximum-Binary-Tree.cpp
 * @brief 最大二叉树(https://leetcode.com/problems/maximum-binary-tree/)
 * @author Finalcheat
 * @date 2017-10-09
 */

/**
 * Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
 * 1. The root is the maximum number in the array.
 * 2. The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
 * 3. The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
 * Construct the maximum tree by the given array and output the root node of this tree.
 * Example 1:
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 *       6
 *     /   \
 *    3     5
 *     \    /
 *      2  0
 *       \
 *        1
 */

/**
 * 最大二叉树的构造，每次从vector取数与根节点对比，比跟节点大则替换成为跟节点，否则从右子树中找出节点替换。
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
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            TreeNode* root = NULL;
            for (size_t i = 0; i < nums.size(); ++i) {
                const int value = nums[i];
                TreeNode* node = new TreeNode(value);
                if (root && root->val > value) {
                    // 找到不大于value的右子树节点
                    TreeNode* tmpNode = root;
                    while (tmpNode->right && tmpNode->right->val > value) {
                        tmpNode = tmpNode->right;
                    }
                    node->left = tmpNode->right;
                    tmpNode->right = node;
                } else {
                    node->left = root;
                    root = node;
                }
            }
            return root;
        }
};
