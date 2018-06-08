/**
 * @file Unique-Binary-Search-Trees.cpp
 * @brief 二叉树的数量(https://leetcode.com/problems/unique-binary-search-trees/) 
 * @author Finalcheat
 * @date 2016-04-14
 */

/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

/**
 * 当有[1, n]节点时，以i为根节点的树，其左子树由[0, i-1]构成， 其右子树由[i+1, n]构成，建成的BTS具有唯一性。
 */

class Solution {
    public:
        int numTrees(int n) {
            if (n <= 0) {
                return 0;
            }
            vector<int> vec(n + 1);  
            vec[0] = 1;  
            vec[1] = 1;  
            for (int i = 2; i <= n; ++i) {
                for (int j = 0; j<i; j++) {
                    vec[i] += vec[j] * vec[i-j-1];  
                }
            }  
            return vec[n];
        }
};
