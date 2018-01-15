/**
 * @file Second-Minimum-Node-In-a-Binary-Tree.cpp
 * @brief 二叉树的第二小节点(https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/)
 * @author Finalcheat
 * @date 2018-01-15
 */

/**
 * Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.
 * Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
 * If no such second minimum value exists, output -1 instead.
 * Example 1:
 * Input:
 *     2
 *    / \
 *   2   5
 *      / \
 *     5   7
 * Output: 5
 * Explanation: The smallest value is 2, the second smallest value is 5.
 * Example 2:
 * Input:
 *     2
 *    / \
 *   2   2
 * Output: -1
 * Explanation: The smallest value is 2, but there isn't any second smallest value.
 */

/**
 * 本来以为是排序二叉树，首先想到的是遍历找第二小的数，后来发现不是。使用set保存遍历二叉树的值，最后取set第二个数即可。
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
        int findSecondMinimumValue(TreeNode* root) {
            std::set<int> s;
            findSecondMinimumValue(root, s);
            std::set<int>::const_iterator it = s.begin();
            if (it == s.end()) {
                return -1;
            }
            ++it;
            if (it != s.end()) {
                return *it;
            }
            return -1;
        }

    private:
        void findSecondMinimumValue(TreeNode* node, std::set<int>& s) {
            if (!node) {
                return;
            }
            findSecondMinimumValue(node->left, s);
            s.insert(node->val);
            findSecondMinimumValue(node->right, s);
        }

};
