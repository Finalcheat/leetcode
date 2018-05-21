/**
 * @file Map-Sum-Pairs.cpp
 * @brief 映射配对之和(https://leetcode.com/problems/map-sum-pairs/description/)
 * @author Finalcheat
 * @date 2018-05-21
 */

/**
 * Implement a MapSum class with insert, and sum methods.
 * For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.
 * For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.
 * Example 1:
 * Input: insert("apple", 3), Output: Null
 * Input: sum("ap"), Output: 3
 * Input: insert("app", 2), Output: Null
 * Input: sum("ap"), Output: 5
 */

/**
 * 用前缀树解决，但有一个地方需要注意，题中要求遇到重复的要覆盖掉，可以用dict保存最后出现的key-val对，每次插入之前检查即可。
 */


class MapSum {
    public:
        /** Initialize your data structure here. */
        MapSum() : root(new TrieNode()) {
        }

        ~MapSum() {
            if (root) {
                freeNode(root);
            }
        }

        void insert(string key, int val) {
            std::unordered_map<string, int>::iterator iter = dict.find(key);
            if (iter != dict.end()) {
                int tmp = iter->second;
                iter->second = val;
                val -= tmp;
            } else {
                dict[key] = val;
            }
            TrieNode* node = root;
            for (size_t i = 0; i < key.size(); ++i) {
                const char c = key[i];
                if (node->children[c] == NULL) {
                    node->children[c] = createTrieNode(val);
                    node = node->children[c];
                } else {
                    node = node->children[c];
                    node->val += val;
                }
            }
        }

        int sum(string prefix) {
            int result = 0;
            TrieNode* node = root;
            for (size_t i = 0; node && i < prefix.size(); ++i) {
                const char c = prefix[i];
                node = node->children[c];
            }
            if (node) {
                result = node->val;
            }
            return result;
        }

    private:
        typedef struct TrieNode {
            TrieNode(const int _v = 0) : val(_v) {
                for (size_t i = 0; i < 256; ++i) {
                    children[i] = NULL;
                }
            }
            int val;
            struct TrieNode* children[256];
        } TrieNode;

        TrieNode* createTrieNode(const int val) {
            TrieNode* node = new TrieNode(val);
            return node;
        }

        void freeNode(TrieNode* node) {
            for (size_t i = 0; i < 256; ++i) {
                if (node->children[i]) {
                    freeNode(node->children[i]);
                    node->children[i] = NULL;
                }
            }
            delete node;
        }

        TrieNode* root;
        std::unordered_map<string, int> dict;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
