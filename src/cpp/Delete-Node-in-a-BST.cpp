/**
 * @file Delete-Node-in-a-BST.cpp
 * @brief 二叉排序树删除节点(https://leetcode.com/problems/delete-node-in-a-bst/description/)
 * @author Finalcheat
 * @date 2018-03-27
 */

/**
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
 * Basically, the deletion can be divided into two stages:
 * 1. Search for a node to remove.
 * 2. If the node is found, delete the node.
 * Note: Time complexity should be O(height of tree).
 * Example:
 * root = [5,3,6,2,4,null,7]
 * key = 3
 *     5
 *    / \
 *   3   6
 *  / \   \
 * 2   4   7
 * Given key to delete is 3. So we find the node with value 3 and delete it.
 * One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
 *     5
 *    / \
 *   4   6
 *  /     \
 * 2       7
 * Another valid answer is [5,2,6,null,4,null,7].
 *     5
 *    / \
 *   2   6
 *    \   \
 *     4   7
 */

/**
 * 找到对应的节点，搜索比它大的下一个节点，找到后替换节点的值同时调整节点指针指向，最后删除节点。
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
        TreeNode* deleteNode(TreeNode* root, int key) {
            TreeNode* parentNode = root;
            TreeNode* node = root;
            // 1. Search for a node to remove.
            while (node && node->val != key) {
                parentNode = node;
                if (node->val < key) {
                    node = node->right;
                } else {
                    node = node->left;
                }
            }

            if (!node) {
                return root;
            }

            // 2. If the node is found, delete the node.
            TreeNode* nextNode = node->right;
            TreeNode* nextParentNode = node;
            while (nextNode && nextNode->left) {
                nextParentNode = nextNode;
                nextNode = nextNode->left;
            }
            if (nextNode) {
                node->val = nextNode->val;
                if (nextNode == nextParentNode->right) {
                    nextParentNode->right = nextNode->right;
                } else {
                    nextParentNode->left = nextNode->right;
                }
                delete nextNode;
            } else {
                if (node == root) {
                    root = node->left;
                } else if (node == parentNode->left) {
                    parentNode->left = node->left;
                } else {
                    parentNode->right = node->left;
                }
                delete node;
            }
            return root;
        }
};
