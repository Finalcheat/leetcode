/**
 * @file Increasing-Order-Search-Tree.cpp
 * @brief Increasing Order Search Tree(https://leetcode.com/problems/increasing-order-search-tree/description/)
 * @author Finalcheat
 * @date 2018-10-20
 */

/**
 * Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.
 * Example 1:
 * Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
 *        5
 *       / \
 *     3    6
 *    / \    \
 *   2   4    8
 *  /        / \
 * 1        7   9
 * Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 *  1
 *   \
 *    2
 *     \
 *      3
 *       \
 *        4
 *         \
 *          5
 *           \
 *            6
 *             \
 *              7
 *               \
 *                8
 *                 \
 *                  9
 */

/**
 * 中序遍历调整指针指向即可。
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
        TreeNode* increasingBST(TreeNode* root) {
            TreeNode* newHead = NULL;
            TreeNode* newTail = NULL;
            TreeNode* cur = root;
            std::stack<TreeNode*> s;
            while (cur || !s.empty()) {
                while (cur) {
                    s.push(cur);
                    cur = cur->left;
                }
                if (!s.empty()) {
                    TreeNode* node = s.top();
                    s.pop();
                    if (node->right) {
                        cur = node->right;
                    }
                    node->left = node->right = NULL;
                    if (newTail) {
                        newTail->right = node;
                        newTail = node;
                    } else {
                        newHead = newTail = node;
                    }
                }
            }
            return newHead;
        }
};
