/**
 * @file Deepest-Leaves-Sum.cpp
 * @brief 最深的叶子节点和(https://leetcode.com/problems/deepest-leaves-sum/)
 * @author Finalcheat
 * @date 2020-05-14
 */

/**
 * Given a binary tree, return the sum of values of its deepest leaves.
 * Example 1:
 * Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 * Output: 15
 * Constraints:
 * * The number of nodes in the tree is between 1 and 10^4.
 * * The value of nodes is between 1 and 100.
 */

/**
 * 层序遍历，最后一层的sum值为所求。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int deepestLeavesSum(TreeNode* root) {
            int sum = 0;
            if (!root) {
                return sum;
            }
            std::queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                const size_t levelSize = q.size();
                sum = 0;
                for (size_t i = 0; i < levelSize; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    sum += node->val;
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }
            return sum;
        }
};
