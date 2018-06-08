/**
 * @file Populating-Next-Right-Pointers-in-Each-Node.cpp
 * @brief 完美二叉树添加next指针(https://leetcode.com/problems/populating-next-right-pointers-in-each-node/) 
 * @author Finalcheat
 * @date 2016-04-16
 */

/**
 * Given a binary tree
 * struct TreeLinkNode {
 *     TreeLinkNode *left;
 *     TreeLinkNode *right;
 *     TreeLinkNode *next;
 * }
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 * Note:
 * * You may only use constant extra space.
 * * You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 * For example,
 * Given the following perfect binary tree,
 *      1
 *     /  \
 *    2    3
 *   / \  / \
 *  4  5  6  7
 * After calling your function, the tree should look like:
 *       1 -> NULL
 *     /  \
 *    2 -> 3 -> NULL
 *   / \  / \
 *  4->5->6->7 -> NULL
 */

/**
 * 使用队列作为辅助结构，用层次遍历的方法在循环中操作每层的节点，调整next指针指向。
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if (root == NULL) {
                return;
            }
            std::queue<TreeLinkNode*> q;
            q.push(root);
            while (!q.empty()) {
                const size_t levelSize = q.size();
                TreeLinkNode* nextLinkNode = NULL;
                for (size_t i = 0; i < levelSize; ++i) {
                    TreeLinkNode* currentNode = q.front();
                    if (currentNode->right) {
                        q.push(currentNode->right);
                    }
                    if (currentNode->left) {
                        q.push(currentNode->left);
                    }
                    currentNode->next = nextLinkNode;
                    nextLinkNode = currentNode;
                    q.pop();
                }
            }
        }
};
