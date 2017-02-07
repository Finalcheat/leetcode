/**
 * @file Keyboard-Row.cpp
 * @brief 键盘行(https://leetcode.com/problems/keyboard-row/)
 * @author Finalcheat
 * @date 2017-02-07
 */

/**
 * Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
 * Example 1:
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * Note:
 * 1. You may use one character in the keyboard more than once.
 * 2. You may assume the input string will only contain letters of alphabet.
 */

/**
 * 将对应的字母与行用哈希表建立映射关系，然后遍历对比即可。
 */

class Solution {

    public:
        vector<string> findWords(vector<string>& words) {
            vector<string> result;
            std::unordered_map<char, int> hashTable;
            _initHashTable(hashTable);
            for (size_t i = 0; i < words.size(); ++i) {
                const string& word = words[i];
                int row = -1;
                bool isSameRow = true;
                for (size_t j = 0; j < word.size(); ++j) {
                    if (row == -1) {
                        row = hashTable[word[j]];
                    } else if (row != hashTable[word[j]]) {
                        isSameRow = false;
                        break;
                    }
                }
                if (isSameRow) {
                    result.push_back(word);
                }
            }
            return result;
        }

    private:
        void _initHashTable(std::unordered_map<char, int> &hashTable) {
            const int dis = 'A' - 'a';
            vector<char> firstRowCharacters{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
            for (size_t i = 0; i < firstRowCharacters.size(); ++i) {
                hashTable[firstRowCharacters[i]] = 1;
                hashTable[firstRowCharacters[i] + dis] = 1;
            }
            vector<char> secondRowCharacters{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
            for (size_t i = 0; i < secondRowCharacters.size(); ++i) {
                hashTable[secondRowCharacters[i]] = 2;
                hashTable[secondRowCharacters[i] + dis] = 2;
            }
            vector<char> thirdRowCharacters{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
            for (size_t i = 0; i < thirdRowCharacters.size(); ++i) {
                hashTable[thirdRowCharacters[i]] = 3;
                hashTable[thirdRowCharacters[i] + dis] = 3;
            }
        }

};
