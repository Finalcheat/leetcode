/**
 * @file N-ary-Tree-Postorder-Traversal.cpp
 * @brief N-ary树后序遍历(https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/)
 * @author Finalcheat
 * @date 2018-08-11
 */

/**
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 */

/**
 * 递归解决清晰明了。
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
        vector<int> postorder(Node* root) {
            vector<int> result;
            _postorder(root, result);
            return result;
        }
    private:
        void _postorder(Node* node, vector<int>& result) {
            if (!node) {
                return;
            }
            const vector<Node*>& children = node->children;
            for (Node* p : children) {
                _postorder(p, result);
            }
            result.push_back(node->val);
        }
};
