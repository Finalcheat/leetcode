/**
 * @file Maximum-Level-Sum-of-a-Binary-Tree.cpp
 * @brief 二叉树的最大水平和(https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)
 * @author Finalcheat
 * @date 2019-09-25
 */

/**
 * Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
 * Return the smallest level X such that the sum of all the values of nodes at level X is maximal.
 * Example 1:
 * Input: [1,7,0,7,-8,null,null]
 * Output: 2
 * Explanation:
 * Level 1 sum = 1.
 * Level 2 sum = 7 + 0 = 7.
 * Level 3 sum = 7 + -8 = -1.
 * So we return the level with the maximum sum which is level 2.
 */

/**
 * 层序遍历累计即可。
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
        int maxLevelSum(TreeNode* root) {
            if (!root) {
                return 0;
            }
            std::queue<TreeNode*> q;
            q.push(root);
            int maximum = root->val;
            int level = 1;
            int maximumLevel = level;
            while (!q.empty()) {
                const size_t levelSize = q.size();
                int levelSum = 0;
                for (size_t i = 0; i < levelSize; ++i) {
                    TreeNode* node = q.front();
                    levelSum += node->val;
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                    q.pop();
                }
                if (levelSum > maximum) {
                    maximum = levelSum;
                    maximumLevel = level;
                }
                ++level;
            }
            return maximumLevel;
        }
};
