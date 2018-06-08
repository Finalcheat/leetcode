/**
 * @file Implement-Magic-Dictionary.cpp
 * @brief 实现魔术字典(https://leetcode.com/problems/implement-magic-dictionary/description/)
 * @author Finalcheat
 * @date 2018-05-27
 */

/**
 * Implement a magic directory with buildDict, and search methods.
 * For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.
 * For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.
 * Example 1:
 * Input: buildDict(["hello", "leetcode"]), Output: Null
 * Input: search("hello"), Output: False
 * Input: search("hhllo"), Output: True
 * Input: search("hell"), Output: False
 * Input: search("leetcoded"), Output: False
 */

/**
 * 建立前缀树，假设第k个字符修改，遍历前缀树到第k个字符的时候搜索其他字符即可，最后外层循环遍历所有位置。
 */


class MagicDictionary {
    public:
        /** Initialize your data structure here. */
        MagicDictionary() : root(new TrieNode()) {
        }

        ~MagicDictionary() {
            if (root) {
                freeNode(root);
            }
        }

        /** Inserts a word into the trie. */
        void insert(const string& word) {
            if (word.empty()) {
                return;
            }
            TrieNode* node = root;
            for (size_t i = 0; i < word.size(); ++i) {
                const int idx = word[i] - 'a';
                assert(idx >= 0);
                assert(idx < 26);
                if (node->children[idx] == NULL) {
                    node->children[idx] = createTrieNode();
                }
                node = node->children[idx];
            }
            ++node->count;
        }

        /** Build a dictionary through a list of words */
        void buildDict(vector<string> dict) {
            for (size_t i = 0; i < dict.size(); ++i) {
                insert(dict[i]);
            }
        }

        /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
        bool search(const string& word) {
            TrieNode* node = root;
            for (size_t i = 0; i < word.size(); ++i) {
                if (modifyIdxCharacter(node, word, i)) {
                    return true;
                }
            }
            return false;
        }

    private:
        typedef struct TrieNode {
            TrieNode() : count(0) {
                for (size_t i = 0; i < 26; ++i) {
                    children[i] = NULL;
                }
            }
            int count;
            struct TrieNode* children[26];
        } TrieNode;

        TrieNode* createTrieNode() {
            return new TrieNode();
        }

        void freeNode(TrieNode* node) {
            for (size_t i = 0; i < 26; ++i) {
                if (node->children[i]) {
                    freeNode(node->children[i]);
                    node->children[i] = NULL;
                }
            }
            delete node;
        }

        TrieNode* _findNode(TrieNode* node, string::const_iterator first, string::const_iterator last) {
            for (; node && first != last; ++first) {
                const int idx = *first - 'a';
                assert(idx >= 0);
                assert(idx < 26);
                node = node->children[idx];
            }
            return node;
        }

        bool modifyIdxCharacter(TrieNode* node, const string& s, const size_t idx) {
            for (size_t i = 0; node && i < s.size(); ++i) {
                const int curIdx = s[i] - 'a';
                assert(curIdx >= 0);
                assert(curIdx < 26);
                if (i != idx) {
                    node = node->children[curIdx];
                } else {
                    for (size_t j = 0; j < 26; ++j) {
                        if (j == curIdx) {
                            continue;
                        }
                        if (node->children[j]) {
                            TrieNode* ptNode = _findNode(node->children[j], s.begin() + i + 1, s.end());
                            if (ptNode && ptNode->count > 0) {
                                return true;
                            }
                        }
                    }
                    return false;
                }
            }
            return false;
        }

        TrieNode* root;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
