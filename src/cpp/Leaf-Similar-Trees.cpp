/**
 * @file Leaf-Similar-Trees.cpp
 * @brief 叶节点相似的树(https://leetcode.com/problems/leaf-similar-trees/description/)
 * @author Finalcheat
 * @date 2018-08-02
 */

/**
 * Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.
 * Two binary trees are considered leaf-similar if their leaf value sequence is the same.
 * Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
 */

/**
 * 深度优先搜索遍历树的叶节点存进vector中，最后对比即可。
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
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            vector<TreeNode*> leafNodes1;
            vector<TreeNode*> leafNodes2;
            _leafSimilar(root1, leafNodes1);
            _leafSimilar(root2, leafNodes2);
            auto iter1 = leafNodes1.begin();
            auto iter2 = leafNodes2.begin();
            while (iter1 != leafNodes1.end() && iter2 != leafNodes2.end()) {
                TreeNode* node1 = *iter1;
                TreeNode* node2 = *iter2;
                if (node1->val != node2->val) {
                    return false;
                }
                ++iter1;
                ++iter2;
            }
            if (iter1 != leafNodes1.end() || iter2 != leafNodes2.end()) {
                return false;
            }
            return true;
        }
    private:
        void _leafSimilar(TreeNode* node, vector<TreeNode*>& leafNodes) {
            if (!node) {
                return;
            }
            if (node->left == NULL && node->right == NULL) {
                leafNodes.push_back(node);
                return;
            }
            _leafSimilar(node->left, leafNodes);
            _leafSimilar(node->right, leafNodes);
        }
};
