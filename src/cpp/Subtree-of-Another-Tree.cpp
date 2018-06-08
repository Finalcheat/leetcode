/**
 * @file Subtree-of-Another-Tree.cpp
 * @brief 另一棵树的子树(https://leetcode.com/problems/subtree-of-another-tree/description/)
 * @author Finalcheat
 * @date 2018-03-08
 */

/**
 * Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
 * Example 1:
 * Given tree s:
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 * Given tree t:
 *    4
 *   / \
 *  1   2
 * Return true, because t has the same structure and node values with a subtree of s.
 * Example 2:
 * Given tree s:
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 *     /
 *    0
 * Given tree t:
 *    4
 *   / \
 *  1   2
 * Return false.
 */

/**
 * 递归判断，比较容易出错，理清各种情况。
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
        bool isSubtree(TreeNode* s, TreeNode* t) {
            if (!s) {
                return false;
            }
            if (_isSubtree(s, t)) {
                return true;
            }
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }

    private:
        bool _isSubtree(TreeNode* s, TreeNode* t) {
            if (!s && !t) {
                return true;
            }
            if (!s || !t) {
                return false;
            }
            if (s->val != t->val) {
                return false;
            }
            return _isSubtree(s->left, t->left) && _isSubtree(s->right, t->right);
        }
};
