/**
 * @file All-Elements-in-Two-Binary-Search-Trees.cpp
 * @brief 两个二叉搜索树中的所有元素升序(https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)
 * @author Finalcheat
 * @date 2020-03-07
 */

/**
 * Given two binary search trees root1 and root2.
 * Return a list containing all the integers from both trees sorted in ascending order.
 * Example 1:
 * Input: root1 = [2,1,4], root2 = [1,0,3]
 * Output: [0,1,1,2,3,4]
 * Example 2:
 * Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
 * Output: [-10,0,0,1,2,5,7,10]
 * Example 3:
 * Input: root1 = [], root2 = [5,1,7,0,2]
 * Output: [0,1,2,5,7]
 * Example 4:
 * Input: root1 = [0,-10,10], root2 = []
 * Output: [-10,0,10]
 * Example 5:
 * Input: root1 = [1,null,8], root2 = [8,1]
 * Output: [1,1,8,8]
 */

/**
 * 中序遍历添加到vector中，最后排序即可。
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        traverseToVector(root1, result);
        traverseToVector(root2, result);
        std::sort(result.begin(), result.end());
        return result;
    }
private:
    void traverseToVector(TreeNode* node, vector<int>& vals) {
        if (!node) {
            return;
        }
        traverseToVector(node->left, vals);
        vals.push_back(node->val);
        traverseToVector(node->right, vals);
    }
};
