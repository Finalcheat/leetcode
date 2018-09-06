/**
 * @file N-ary-Tree-Preorder-Traversal.cpp
 * @brief N-ary树的前序遍历(https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/)
 * @author Finalcheat
 * @date 2018-08-07
 */

/**
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 */

/**
 * 递归简单，非递归方法需要考虑的问题较多。
 */


/*
// Definition for a Node.
class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};
*/
class Solution {
    public:
        vector<int> preorder(Node* root) {
            vector<int> result;
            _preorder(root, result);
            return result;
        }
    private:
        void _preorder(Node* node, vector<int>& result) {
            if (!node) {
                return;
            }
            result.push_back(node->val);
            const vector<Node*>& children = node->children;
            for (Node* child : children) {
                _preorder(child, result);
            }
        }
};
