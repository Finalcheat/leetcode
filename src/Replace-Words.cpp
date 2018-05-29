/**
 * @file Replace-Words.cpp
 * @brief 替换单词(https://leetcode.com/problems/replace-words/description/)
 * @author Finalcheat
 * @date 2018-05-29
 */

/**
 * In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.
 * Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.
 * You need to output the sentence after the replacement.
 * Example 1:
 * Input: dict = ["cat", "bat", "rat"]
 * sentence = "the cattle was rattled by the battery"
 * Output: "the cat was rat by the bat"
 */

/**
 * 建立前缀树，搜索到最短前缀返回root，不匹配返回原单词。
 */


class Solution {
    public:
        Solution() : root(createTrieNode()) {
        }

        ~Solution() {
            if (root) {
                freeNode(root);
            }
        }

    public:
        string replaceWords(vector<string>& dict, string sentence) {
            buildDict(dict);
            vector<string> words = split(sentence, ' ');
            string result;
            for (size_t i = 0; i < words.size(); ++i) {
                const string& word = words[i];
                result += findPrefix(word);
                result += " ";
            }
            if (!result.empty()) {
                result.pop_back();
            }
            return result;
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
        void buildDict(const vector<string>& dict) {
            for (size_t i = 0; i < dict.size(); ++i) {
                insert(dict[i]);
            }
        }

        std::vector<std::string> split(const std::string &s, char delim) {
            std::stringstream ss(s);
            std::string item;
            std::vector<std::string> elems;
            while (std::getline(ss, item, delim)) {
                elems.push_back(std::move(item));
            }
            return elems;
        }

        string findPrefix(const string& word) {
            TrieNode* node = root;
            string prefix;
            for (size_t i = 0; i < word.size(); ++i) {
                const char c = word[i];
                const int idx = c - 'a';
                assert(idx >= 0);
                assert(idx < 26);
                if (node->children[idx] == NULL) {
                    return word;
                }
                prefix.push_back(c);
                node = node->children[idx];
                if (node->count > 0) {
                    return prefix;
                }
            }
            return word;
        }

        TrieNode* root;
};
