/**
 * @file Construct-String-from-Binary-Tree.cpp
 * @brief 从字符串构造二叉树(https://leetcode.com/problems/construct-string-from-binary-tree/description/)
 * @author Finalcheat
 * @date 2018-03-14
 */

/**
 * You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
 * The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.
 * Example 1:
 * Input: Binary tree: [1,2,3,4]
 *        1
 *      /   \
 *     2     3
 *    /
 *   4
 * Output: "1(2(4))(3)"
 * Explanation: Originallay it needs to be "1(2(4)())(3()())",
 * but you need to omit all the unnecessary empty parenthesis pairs.
 * And it will be "1(2(4))(3)".
 * Example 2:
 * Input: Binary tree: [1,2,3,null,4]
 *        1
 *      /   \
 *     2     3
 *      \
 *       4
 * Output: "1(2()(4))(3)"
 * Explanation: Almost the same as the first example,
 * except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
 */

/**
 * 二叉树的问题最适合用递归解决。
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
        string tree2str(TreeNode* t) {
            string result;
            _tree2str(t, result);
            return result;
        }

    private:
        void _tree2str(TreeNode* t, string& s) {
            if (!t) {
                return;
            }
            s += std::to_string(t->val);
            if (t->right) {
                s += "(";
                _tree2str(t->left, s);
                s += ")(";
                _tree2str(t->right, s);
                s += ")";
            } else if (t->left) {
                s += "(";
                _tree2str(t->left, s);
                s += ")";
            }
        }

};
