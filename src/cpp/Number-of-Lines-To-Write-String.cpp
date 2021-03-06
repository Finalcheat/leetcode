/**
 * @file Number-of-Lines-To-Write-String.cpp
 * @brief 写字符串的行数(https://leetcode.com/problems/number-of-lines-to-write-string/description/)
 * @author Finalcheat
 * @date 2018-03-30
 */

/**
 * We are to write the letters of a given string S, from left to right into lines. Each line has maximum width 100 units, and if writing a letter would cause the width of the line to exceed 100 units, it is written on the next line. We are given an array widths, an array where widths[0] is the width of 'a', widths[1] is the width of 'b', ..., and widths[25] is the width of 'z'.
 * Now answer two questions: how many lines have at least one character from S, and what is the width used by the last such line? Return your answer as an integer list of length 2.
 * Example :
 * Input:
 * widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
 * S = "abcdefghijklmnopqrstuvwxyz"
 * Output: [3, 60]
 * Explanation:
 * All letters have the same length of 10. To write all 26 letters,
 * we need two full lines and one line with 60 units.
 * Example :
 * Input:
 * widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
 * S = "bbbcccdddaaa"
 * Output: [2, 4]
 * Explanation:
 * All letters except 'a' have the same length of 10, and
 * "bbbcccdddaa" will cover 9 * 10 + 2 * 4 = 98 units.
 * For the last 'a', it is written on the second line because
 * there is only 2 units left in the first line.
 * So the answer is 2 lines, plus 4 units in the second line.
 */

/**
 * 很简单的题目，遍历累加判断即可。
 */


class Solution {
    public:
        vector<int> numberOfLines(vector<int>& widths, string S) {
            vector<int> result;
            int row = 1;
            int columnWidth = 0;
            for (size_t i = 0; i < S.size(); ++i) {
                const int width = widths[S[i] - 'a'];
                columnWidth += width;
                if (columnWidth > 100) {
                    ++row;
                    columnWidth = width;
                }
            }
            result.push_back(row);
            result.push_back(columnWidth);
            return result;
        }
};
