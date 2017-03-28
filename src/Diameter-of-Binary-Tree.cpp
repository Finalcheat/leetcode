/**
 * @file Diameter-of-Binary-Tree.cpp
 * @brief Diameter of Binary Tree(https://leetcode.com/problems/diameter-of-binary-tree/)
 * @author Finalcheat
 * @date 2017-03-28
 */

/**
 * Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 * Example:
 * Given a binary tree 
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * Note: The length of path between two nodes is represented by the number of edges between them.
 */

/**
 * 假设最长路径通过当前节点的话，最长路径等1+左右子树的深度，所以只要将通过当前节点的最长路径与左右子树(递归)进行对比即可找出最大值。
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
        int diameterOfBinaryTree(TreeNode* root) {
            int maxLength = _diameterOfBinaryTree(root);
            if (maxLength > 0) {
                maxLength -= 1;
            }
            return maxLength;
        }
        
    private:
        int _diameterOfBinaryTree(TreeNode* node) {
            if (node == NULL) {
                return 0;
            }
            int leftTreeDepth = TreeDepth(node->left);
            int rightTreeDepth = TreeDepth(node->right);
            int maxLength = std::max(1 + leftTreeDepth + rightTreeDepth, _diameterOfBinaryTree(node->left));
            maxLength = std::max(maxLength, _diameterOfBinaryTree(node->right));
            return maxLength;
        }
        
        int TreeDepth(TreeNode* node) {
            if (node == NULL) {
                return 0;
            }
            return 1 + std::max(TreeDepth(node->left), TreeDepth(node->right));
        }
};
