/**
 * @file Sum-of-Nodes-with-Even-Valued-Grandparent.cpp
 * @brief 具有偶数祖父节点的节点的和(https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/)
 * @author Finalcheat
 * @date 2020-05-08
 */

/**
 * Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)
 * If there are no nodes with an even-valued grandparent, return 0.
 * Example 1:
 * Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * Output: 18
 * Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
 * Constraints:
 * * The number of nodes in the tree is between 1 and 10^4.
 * * The value of nodes is between 1 and 100.
 */

/**
 * 递归相加偶数祖父节点值即可。
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
        int sumEvenGrandparent(TreeNode* root) {
            if (!root) {
                return 0;
            }
            return sumEvenNode(root) + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
        }
    private:
        int sumEvenNode(TreeNode* node) {
            if (node->val % 2 != 0) {
                return 0;
            }
            int sum = 0;
            TreeNode* leftNode = node->left;
            if (leftNode) {
                if (leftNode->left) {
                    sum += leftNode->left->val;
                }
                if (leftNode->right) {
                    sum += leftNode->right->val;
                }
            }
            TreeNode* rightNode = node->right;
            if (rightNode) {
                if (rightNode->left) {
                    sum += rightNode->left->val;
                }
                if (rightNode->right) {
                    sum += rightNode->right->val;
                }
            }
            return sum;
        }
};
