/**
 * @file Design-HashSet.cpp
 * @brief 设计集合表(https://leetcode.com/problems/design-hashset/description/)
 * @author Finalcheat
 * @date 2018-08-27
 */

/**
 * Design a HashSet without using any built-in hash table libraries.
 * To be specific, your design should include these functions:
 * * add(value): Insert a value into the HashSet.
 * * contains(value) : Return whether the value exists in the HashSet or not.
 * * remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
 * Example:
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);
 * hashSet.add(2);
 * hashSet.contains(1);    // returns true
 * hashSet.contains(3);    // returns false (not found)
 * hashSet.add(2);
 * hashSet.contains(2);    // returns true
 * hashSet.remove(2);
 * hashSet.contains(2);    // returns false (already removed)
 */

/**
 * 把hashmap的value去掉改改就行了。
 */


class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        const size_t len = 1024;
        v.resize(len, NULL);
    }

    void add(int key) {
        int pos = dictIntHashFunction(key) & (v.size() - 1);
        struct dictEntry* p = v[pos];
        while (p && p->key != key) {
            p = p->next;
        }
        if (!p) {
            struct dictEntry* newEntry = new dictEntry();
            newEntry->key = key;
            newEntry->next = v[pos];
            v[pos] = newEntry;
        }
    }

    void remove(int key) {
        int pos = dictIntHashFunction(key) & (v.size() - 1);
        struct dictEntry* p = v[pos];
        struct dictEntry* prev = NULL;
        while (p && p->key != key) {
            prev = p;
            p = p->next;
        }
        if (p) {
            if (prev) {
                prev->next = p->next;
            } else {
                v[pos] = p->next;
            }
            delete p;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos = dictIntHashFunction(key) & (v.size() - 1);
        struct dictEntry* p = v[pos];
        while (p && p->key != key) {
            p = p->next;
        }
        if (p) {
            return true;
        }
        return false;
    }

private:
    int dictIntHashFunction(int key)
    {
        key += ~(key << 15);
        key ^=  (key >> 10);
        key +=  (key << 3);
        key ^=  (key >> 6);
        key += ~(key << 11);
        key ^=  (key >> 16);
        return key;
    }

    typedef struct dictEntry {
        int key;
        struct dictEntry *next;
    } dictEntry;

    std::vector<dictEntry*> v;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
