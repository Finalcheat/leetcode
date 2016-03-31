/**
 * @file Binary-Search-Tree-Iterator.cpp
 * @brief 二叉搜索树迭代器(https://leetcode.com/problems/binary-search-tree-iterator/)
 * @author Finalcheat
 * @date 2016-03-31
 */

/**
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 * Calling next() will return the next smallest number in the BST.
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 */

/**
 * 二叉搜索树的迭代器，其实也就是模仿二叉搜索树中序遍历的做法，一直向左走用栈保存节点，然后出栈向右走就是中序遍历了。
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    public:
        BSTIterator(TreeNode *root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !s.empty();
        }

        /** @return the next smallest number */
        int next() {
            TreeNode* node = s.top();
            s.pop();
            TreeNode* rightNode = node->right;
            while (rightNode) {
                s.push(rightNode);
                rightNode = rightNode->left;
            }
            return node->val;
        }

    private:
        std::stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
