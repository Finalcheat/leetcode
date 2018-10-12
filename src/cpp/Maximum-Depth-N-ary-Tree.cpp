/**
 * @file Maximum-Depth-of-N-ary-Tree.cpp
 * @brief N-ary树的最大深度(https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/)
 * @author Finalcheat
 * @date 2018-08-18
 */

/**
 * Given a n-ary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

/**
 * 递归求解很简单。
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
        int maxDepth(Node* root) {
            if (!root) {
                return 0;
            }
            int maximum = 0;
            const vector<Node*>& children = root->children;
            for (Node* child : children) {
                maximum = std::max(maximum, maxDepth(child));
            }
            return 1 + maximum;
        }
};
