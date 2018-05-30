/**
 * @file Add-and-Search-Word-Data-structure-design.cpp
 * @brief 添加和搜索单词(https://leetcode.com/problems/add-and-search-word-data-structure-design/description/)
 * @author Finalcheat
 * @date 2018-05-30
 */

/**
 * Design a data structure that supports the following two operations:
 * void addWord(word)
 * bool search(word)
 * search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
 * Example:
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 */

/**
 * 建立前缀树，搜索遇到.字符遍历26个字符递归即可。
 */


class WordDictionary {
    public:
        /** Initialize your data structure here. */
        WordDictionary() : root(createTrieNode()) {
        }

        ~WordDictionary() {
            if (root) {
                freeNode(root);
            }
        }

        /** Adds a word into the data structure. */
        void addWord(string word) {
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

        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
        bool search(string word) {
            TrieNode* node = root;
            for (size_t i = 0; node && i < word.size(); ++i) {
                const char c = word[i];
                if (c != '.') {
                    const int idx = c - 'a';
                    assert(idx >= 0);
                    assert(idx < 26);
                    node = node->children[idx];
                } else {
                    return _findNode(node, word.begin() + i, word.end());
                }
            }
            if (node && node->count > 0) {
                return true;
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

        bool _findNode(TrieNode* node, string::const_iterator first, string::const_iterator last) {
            for (; node && first != last; ++first) {
                const char c = *first;
                if (c == '.') {
                    for (size_t i = 0; i < 26; ++i) {
                        if (node->children[i]) {
                            if (_findNode(node->children[i], first + 1, last)) {
                                return true;
                            }
                        }
                    }
                    return false;
                } else {
                    const int idx = c - 'a';
                    assert(idx >= 0);
                    assert(idx < 26);
                    node = node->children[idx];
                }
            }
            if (node && node->count > 0) {
                return true;
            }
            return false;
        }

        TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
