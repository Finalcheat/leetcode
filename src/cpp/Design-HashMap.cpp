/**
 * @file Design-HashMap.cpp
 * @brief 设计哈希表(https://leetcode.com/problems/design-hashmap/description/)
 * @author Finalcheat
 * @date 2018-08-26
 */

/**
 * Design a HashMap without using any built-in hash table libraries.
 * To be specific, your design should include these functions:
 * * put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
 * * get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
 * * remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.
 * Example:
 * MyHashMap hashMap = new MyHashMap();
 * hashMap.put(1, 1);
 * hashMap.put(2, 2);
 * hashMap.get(1);            // returns 1
 * hashMap.get(3);            // returns -1 (not found)
 * hashMap.put(2, 1);          // update the existing value
 * hashMap.get(2);            // returns 1
 * hashMap.remove(2);          // remove the mapping for 2
 * hashMap.get(2);            // returns -1 (not found)
 */

/**
 * 设计好hash函数用开链法解决冲突就行了。
 */


class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        const size_t len = 1024;
        v.resize(len, NULL);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos = dictIntHashFunction(key) & (v.size() - 1);
        struct dictEntry* p = v[pos];
        while (p && p->key != key) {
            p = p->next;
        }
        if (p) {
            p->value = value;
        } else {
            struct dictEntry* newEntry = new dictEntry();
            newEntry->key = key;
            newEntry->value = value;
            newEntry->next = v[pos];
            v[pos] = newEntry;
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = dictIntHashFunction(key) & (v.size() - 1);
        struct dictEntry* p = v[pos];
        while (p && p->key != key) {
            p = p->next;
        }
        if (p) {
            return p->value;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
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
        int value;
        struct dictEntry *next;
    } dictEntry;

    std::vector<dictEntry*> v;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
