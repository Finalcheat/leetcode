/**
 * @file N-ary-Tree-Level-Order-Traversal.cpp
 * @brief N-ary树的层序遍历(https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/)
 * @author Finalcheat
 * @date 2018-08-08
 */

/**
 * Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 */

/**
 * 使用队列作为辅助先进先出，按层进队出队即可。
 */


/*
// Definition for a Node.
class Node {
    public:
        int val = NULL;
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
        vector<vector<int>> levelOrder(Node* root) {
            vector< vector<int> > result;
            if (!root) {
                return result;
            }
            std::queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                const size_t levelLen = q.size();
                vector<int> level;
                for (size_t i = 0; i < levelLen; ++i) {
                    Node* node = q.front();
                    q.pop();
                    level.push_back(node->val);
                    const vector<Node*>& children = node->children;
                    for (const auto child : children) {
                        q.push(child);
                    }
                }
                result.push_back(level);
            }
            return result;
        }
};
