/**
 * @file Insert-into-a-Binary-Search-Tree.cpp
 * @brief 二叉搜索树插入(https://leetcode.com/problems/insert-into-a-binary-search-tree/description/)
 * @author Finalcheat
 * @date 2018-09-09
 */

/**
 * Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
 * Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
 * For example,
 * Given the tree:
 *         4
 *        / \
 *       2   7
 *      / \
 *     1   3
 * And the value to insert: 5
 * You can return this binary search tree:
 *          4
 *        /   \
 *       2     7
 *      / \   /
 *     1   3 5
 * This tree is also valid:
 *          5
 *        /   \
 *       2     7
 *      / \
 *     1   3
 *          \
 *           4
 */

/**
 * 二叉搜索树搜索到插入位置父节点，最后判断当前值跟父节点大小关系插入相应位置即可。
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
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            TreeNode* prevNode = NULL;
            TreeNode* node = root;
            while (node) {
                prevNode = node;
                if (node->val <= val) {
                    node = node->right;
                } else {
                    node = node->left;
                }
            }
            if (prevNode) {
                if (prevNode->val <= val) {
                    prevNode->right = new TreeNode(val);
                } else {
                    prevNode->left = new TreeNode(val);
                }
                return root;
            }
            root = new TreeNode(val);
            return root;
        }
};
