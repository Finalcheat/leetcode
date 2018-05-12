/**
 * @file Goat-Latin.cpp
 * @brief Goat Latin(https://leetcode.com/problems/goat-latin/description/)
 * @author Finalcheat
 * @date 2018-05-12
 */

/**
 * A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.
 * We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)
 * The rules of Goat Latin are as follows:
 * * If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
 *   For example, the word 'apple' becomes 'applema'.
 * * If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
 *   For example, the word "goat" becomes "oatgma".
 * * Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
 *   For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
 * Return the final sentence representing the conversion from S to Goat Latin.
 * Example 1:
 * Input: "I speak Goat Latin"
 * Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
 * Example 2:
 * Input: "The quick brown fox jumped over the lazy dog"
 * Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 */

/**
 * 按照规则执行即可，没什么难度。
 */


class Solution {
    public:
        string toGoatLatin(string S) {
            std::vector<std::string> words = split(S, ' ');
            std::string result;
            for (size_t i = 0; i < words.size(); ++i) {
                const std::string& word = words[i];
                char firstLetter = word[0];
                if (isVowel(firstLetter)) {
                    result += word;
                } else {
                    result += word.substr(1, word.size() - 1);
                    result += firstLetter;
                }
                result += "ma";
                result += std::string(i + 1, 'a');
                result += " ";
            }
            result.pop_back();
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
        bool isVowel(char c) {
            switch (c) {
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    return true;
                default:
                    return false;
            }
            return false;
        }
};
