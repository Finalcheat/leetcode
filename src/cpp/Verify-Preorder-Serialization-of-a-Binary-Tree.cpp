/**
 * @file Verify-Preorder-Serialization-of-a-Binary-Tree.cpp
 * @brief 验证二叉树前序遍历序列化(https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/)
 * @author Finalcheat
 * @date 2018-08-10
 */

/**
 * One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
 *      _9_
 *     /   \
 *    3     2
 *   / \   / \
 *  4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 * For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 * Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
 * Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
 * You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
 * Example 1:
 * Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Output: true
 * Example 2:
 * Input: "1,#"
 * Output: false
 * Example 3:
 * Input: "9,#,#,1"
 * Output: false
 */

/**
 * 看到一种用出度入度的解决方法很妙。
 * 对于二叉树，叶节点（如题目中的#），那么有
 * 所有的非叶节点有2个出度和1个入度（根节点除外）
 * 所有的叶节点提供0个出度和1个入度
 * 计算diff = 出度 – 入度，最后diff = 0
 */


class Solution {
    public:
        bool isValidSerialization(string preorder) {
            std::vector<std::string> vs = split(preorder, ',');
            if (vs.size() % 2 == 0) {
                return false;
            }
            int diff = 1;
            for (const auto& value : vs) {
                --diff;
                if (diff < 0) {
                    return false;
                }
                if (value != "#") {
                    diff += 2;
                }
            }
            return diff == 0;
        }
    private:
        std::vector<std::string> split(const std::string &s, char delim) {
            std::stringstream ss(s);
            std::string item;
            std::vector<std::string> elems;
            while (std::getline(ss, item, delim)) {
                elems.push_back(std::move(item));
            }
            return elems;
        }
};
