/**
 * @file Search-in-a-Binary-Search-Tree.cpp
 * @brief 二叉搜索树搜索值(https://leetcode.com/problems/search-in-a-binary-search-tree/description/)
 * @author Finalcheat
 * @date 2018-08-09
 */

/**
 * Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.
 * For example,
 * Given the tree:
 *         4
 *        / \
 *       2   7
 *      / \
 *     1   3
 * And the value to search: 2
 * You should return this subtree:
 *       2
 *      / \
 *     1   3
 * In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.
 * Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.
 */

/**
 * 类似于二分搜索，当前节点等于要搜索的值就是所求，小于就往右子树走，否则就往左子树走。
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
        TreeNode* searchBST(TreeNode* root, int val) {
            TreeNode* curNode = root;
            while (curNode && curNode->val != val) {
                if (curNode->val < val) {
                    curNode = curNode->right;
                } else {
                    curNode = curNode->left;
                }
            }
            return curNode;
        }
};
