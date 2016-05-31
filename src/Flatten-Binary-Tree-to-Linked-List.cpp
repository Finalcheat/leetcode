/**
 * @file Flatten-Binary-Tree-to-Linked-List.cpp
 * @brief 二叉树前序遍历转成链表(https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
 * @author Finalcheat
 * @date 2016-05-31
 */

/**
 * Given a binary tree, flatten it to a linked list in-place.
 * For example,
 * Given
 *       1
 *      / \
 *     2   5
 *    / \   \
 *   3   4   6
 * The flattened tree should look like:
 * 1
 *  \
 *   2
 *    \
 *     3
 *      \
 *       4
 *        \
 *         5
 *          \
 *           6
 */

/**
 * 前序遍历放到队列中，然后从队列中取出元素调整指针指向即可。
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
        void flatten(TreeNode* root) {
            if (!root) {
                return;
            }
            std::stack<TreeNode*> s;
            std::queue<TreeNode*> q;
            s.push(root);
            while (!s.empty()) {
                TreeNode* node = s.top();
                s.pop();
                if (node->right) {
                    s.push(node->right);
                }
                if (node->left) {
                    s.push(node->left);
                }
                q.push(node);
            }
            
            TreeNode* preNode = NULL;
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                node->left = NULL;
                node->right = NULL;
                if (preNode) {
                    preNode->right = node;
                }
                preNode = node;
            }
        }
};
