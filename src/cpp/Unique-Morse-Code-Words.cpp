/**
 * @file Unique-Morse-Code-Words.cpp
 * @brief 独特的莫尔斯码字(https://leetcode.com/problems/unique-morse-code-words/description/)
 * @author Finalcheat
 * @date 2018-03-29
 */

/**
 * International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
 * For convenience, the full table for the 26 letters of the English alphabet is given below:
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.
 * Return the number of different transformations among all words we have.
 * Example:
 * Input: words = ["gin", "zen", "gig", "msg"]
 * Output: 2
 * Explanation:
 * The transformation of each word is:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 * There are 2 different transformations, "--...-." and "--...--.".
 * Note:
 * The length of words will be at most 100.
 * Each words[i] will have length in range [1, 12].
 * words[i] will only consist of lowercase letters.
 */

/**
 * 直接查找替换最后用set去重即可。
 */


class Solution {
    public:
        int uniqueMorseRepresentations(vector<string>& words) {
            std::map<char, string> m;
            string s[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                        "..", ".---", "-.-",".-..", "--","-.","---",".--.","--.-",
                        ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
            for (size_t i = 0; i < sizeof(s) / sizeof(string); ++i) {
                m['a' + i] = s[i];
            }
            std::set<string> ss;
            for (const auto& word : words) {
                string result;
                for (char c : word) {
                    result += m[c];
                }
                ss.insert(result);
            }
            return ss.size();
        }
};
