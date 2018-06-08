/**
 * @file Minimum-Distance-Between-BST-Nodes.cpp
 * @brief BST节点之间的最小距离(https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/)
 * @author Finalcheat
 * @date 2018-03-10
 */

/**
 * Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.
 * Example :
 * Input: root = [4,2,6,1,3,null,null]
 * Output: 1
 * Explanation:
 * Note that root is a TreeNode object, not an array.
 * The given tree [4,2,6,1,3,null,null] is represented by the following diagram:
 *           4
 *         /   \
 *       2      6
 *      / \
 *     1   3
 * while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
 */

/**
 * BST按中序遍历将val存到vector中，最小距离必定出现在相邻之间。
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
        int minDiffInBST(TreeNode* root) {
            vector<int> values;
            inorderTraversal(root, values);
            assert(values.size() >= 2);
            int minimum = std::abs(values[0] - values[1]);
            for (size_t i = 2; i < values.size(); ++i) {
                const int diff = std::abs(values[i] - values[i - 1]);
                if (diff < minimum) {
                    minimum = diff;
                }
            }
            return minimum;
        }

    private:
        void inorderTraversal(TreeNode* node, vector<int>& values) {
            if (!node) {
                return;
            }
            inorderTraversal(node->left, values);
            values.push_back(node->val);
            inorderTraversal(node->right, values);
        }

};
