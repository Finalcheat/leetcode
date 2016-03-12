/**
 * @file Convert-Sorted-Array-to-Binary-Search-Tree.cpp
 * @brief 将已排序的数组转成二叉搜索树(https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
 * @author Finalcheat
 * @date 2016-03-12
 */

/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

/**
 * 数组已排序，假设只有3个数[1 2 3]，以数组中间值2为根，左边1为左子树，右边3为右子树。
 * 所以对于n > 3的数组可以用同样的思想，递归即可。
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
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            if (nums.empty()) {
                return NULL;
            }
            TreeNode* root = _sortedArrayToBST(nums, 0, nums.size() - 1);
            return root;
        }
        
    private:
        TreeNode* _sortedArrayToBST(const vector<int>& nums, const int begin, const int end) {
            if (begin > end) {
                return NULL;
            }
            const int middle = (begin + end) / 2;
            TreeNode* root = new TreeNode(nums[middle]);
            root->left = _sortedArrayToBST(nums, begin, middle - 1);
            root->right = _sortedArrayToBST(nums, middle + 1, end);
            return root;
        }
};
