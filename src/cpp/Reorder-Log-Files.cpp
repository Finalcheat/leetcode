/**
 * @file Reorder-Log-Files.cpp
 * @brief 重新排列日志文件(https://leetcode.com/problems/reorder-log-files)
 * @author Finalcheat
 * @date 2018-12-02
 */

/**
 * You have an array of logs.  Each log is a space delimited string of words.
 * For each log, the first word in each log is an alphanumeric identifier.  Then, either:
 * * Each word after the identifier will consist only of lowercase letters, or;
 * * Each word after the identifier will consist only of digits.
 * We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.
 * Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.
 * Return the final order of the logs.
 * Example 1:
 * Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
 * Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 */

/**
 * 筛选出字母和数字，排序借助map即可。
 */


class Solution {
    public:
        vector<string> reorderLogFiles(vector<string>& logs) {
            std::multimap<std::string, std::string> letterMap;
            std::vector<std::string> numVector;
            for (const std::string& log : logs) {
                size_t idx = 0;
                size_t last = log.size();
                // find space
                while (idx < last && log[idx] != ' ') {
                    ++idx;
                }
                // skip space
                while (idx < last && log[idx] == ' ') {
                    ++idx;
                }
                assert(idx < last);
                const char c = log[idx];
                if (c >= '0' && c <= '9') {
                    numVector.push_back(log);
                } else {
                    const std::string letter = log.substr(idx);
                    letterMap.insert(std::make_pair(letter, log));
                }
            }

            std::vector<std::string> result;
            for (const auto& pair : letterMap) {
                result.push_back(pair.second);
            }
            for (const std::string& s : numVector) {
                result.push_back(s);
            }
            return result;
        }
};
