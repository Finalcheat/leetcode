/**
 * @file Occurrences-After-Bigram..cpp
 * @brief 三元组(https://leetcode.com/problems/occurrences-after-bigram/)
 * @author Finalcheat
 * @date 2019-09-18
 */

/**
 * Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.
 * For each such occurrence, add "third" to the answer, and return the answer.
 * Example 1:
 * Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
 * Output: ["girl","student"]
 * Example 2:
 * Input: text = "we will we will rock you", first = "we", second = "will"
 * Output: ["we","rock"]
 */

/**
 * 分割遍历即可
 */

class Solution {
    public:
        vector<string> findOcurrences(string text, string first, string second) {
            vector<string> strArrs = split(text, ' ');
            vector<string> result;
            if (strArrs.size() < 3) {
                return result;
            }
            for (size_t i = 2; i < strArrs.size(); ++i) {
                if (strArrs[i - 2] == first && strArrs[i - 1] == second) {
                    result.push_back(strArrs[i]);
                }
            }
            return result;
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
