/**
 * @file Populating-Next-Right-Pointers-in-Each-Node-II.cpp
 * @brief 二叉树添加next指针(https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/) 
 * @author Finalcheat
 * @date 2016-04-27
 */

/**
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 * What if the given tree could be any binary tree? Would your previous solution still work?
 * For example,
 * Given the following binary tree,
 *          1
 *         /  \
 *        2    3
 *       / \    \
 *      4   5    7
 * After calling your function, the tree should look like:
 *          1 -> NULL
 *         /  \
 *        2 -> 3 -> NULL
 *       / \    \
 *      4-> 5 -> 7 -> NULL
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
