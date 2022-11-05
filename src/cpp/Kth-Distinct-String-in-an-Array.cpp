/**
 * @file Kth-Distinct-String-in-an-Array.cpp
 * @brief Kth Distinct String in an Array(https://leetcode.com/problems/kth-distinct-string-in-an-array/)
 * @author Finalcheat
 * @date 2022-11-05
 */

/**
 * A distinct string is a string that is present only once in an array.
 * Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".
 * Note that the strings are considered in the order in which they appear in the array.
 * Example 1:
 * Input: arr = ["d","b","c","b","c","a"], k = 2
 * Output: "a"
 * Explanation:
 * The only distinct strings in arr are "d" and "a".
 * "d" appears 1st, so it is the 1st distinct string.
 * "a" appears 2nd, so it is the 2nd distinct string.
 * Since k == 2, "a" is returned. 
 * Example 2:
 * Input: arr = ["aaa","aa","a"], k = 1
 * Output: "aaa"
 * Explanation:
 * All strings in arr are distinct, so the 1st string "aaa" is returned.
 * Example 3:
 * Input: arr = ["a","b","a"], k = 3
 * Output: ""
 * Explanation:
 * The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
 * Constraints:
 * 1 <= k <= arr.length <= 1000
 * 1 <= arr[i].length <= 5
 * arr[i] consists of lowercase English letters.
 */

/**
 * 两次遍历，第一次统计字符串出现次数，第二次扫描结果。
 */

class Solution {
public:
  string kthDistinct(vector<string>& arr, int k) {
    std::map<string, int> m;
    for (size_t i = 0; i < arr.size(); ++i) {
      m[arr[i]]++;
    }
    for (size_t i = 0; i < arr.size(); ++i) {
      if (m[arr[i]] != 1) {
        continue;
      }
      if (--k <= 0) {
        return arr[i];
      }
    }
    return "";
  }
};
