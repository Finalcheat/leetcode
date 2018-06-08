/**
 * @file Implement-Trie-Prefix-Tree.cpp
 * @brief 实现前缀树(https://leetcode.com/problems/implement-trie-prefix-tree/description/)
 * @author Finalcheat
 * @date 2018-05-22
 */

/**
 * Implement a trie with insert, search, and startsWith methods.
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 */

/**
 * 前缀树的标准做法实现即可，因为限定小写字母，空间可大幅减少。
 */


class Trie {
    public:
        /** Initialize your data structure here. */
        Trie() : root(createTrieNode()) {

        }

        ~Trie() {
            if (root) {
                freeNode(root);
            }
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
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

        /** Returns if the word is in the trie. */
        bool search(string word) {
            TrieNode* node = traverseTrie(root, word);
            if (node && node->count != 0) {
                return true;
            }
            return false;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            TrieNode* node = traverseTrie(root, prefix);
            return node != NULL;
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

        TrieNode* traverseTrie(TrieNode* node, const string& s) {
            for (size_t i = 0; node && i < s.size(); ++i) {
                const int idx = s[i] - 'a';
                assert(idx >= 0);
                assert(idx < 26);
                node = node->children[idx];
            }
            return node;
        }

        TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
