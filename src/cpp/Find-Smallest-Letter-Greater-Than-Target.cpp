/**
 * @file Find-Smallest-Letter-Greater-Than-Target.cpp
 * @brief 查找比目标值大的最小字母(https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/)
 * @author Finalcheat
 * @date 2018-01-10
 */

/**
 * Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.
 * Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
 *
 * Examples:
 * Input:
 * letters = ["c", "f", "j"]
 * target = "a"
 * Output: "c"
 * Input:
 * letters = ["c", "f", "j"]
 * target = "c"
 * Output: "f"
 * Input:
 * letters = ["c", "f", "j"]
 * target = "d"
 * Output: "f"
 * Input:
 * letters = ["c", "f", "j"]
 * target = "g"
 * Output: "j"
 * Input:
 * letters = ["c", "f", "j"]
 * target = "j"
 * Output: "c"
 * Input:
 * letters = ["c", "f", "j"]
 * target = "k"
 * Output: "c"
 */

/**
 * 用二分搜索法查找大于目标值的位置，最后判断是否大于目标值，是则直接返回，否则返回第一个位置的元素。
 */


class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            size_t index = 0;
            size_t end = letters.size() - 1;
            while (index < end) {
                const size_t middle = index + (end - index) / 2;
                if (letters[middle] <= target) {
                    index = middle + 1;
                } else {
                    end = middle;
                }
            }
            if (letters[index] > target) {
                return letters[index];
            } else {
                return letters[0];
            }
        }
};
