/**
 * @file Insert-Delete-GetRandom-O1.cpp
 * @brief Insert Delete GetRandom O(1)(https://leetcode.com/problems/insert-delete-getrandom-o1/)
 * @author Finalcheat
 * @date 2017-03-18
 */

/**
 * Design a data structure that supports all following operations in average O(1) time.
 * 1. insert(val): Inserts an item val to the set if not already present.
 * 2. remove(val): Removes an item val from the set if present.
 * 3. getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 * Example:
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 * // Since 2 is the only number in the set, getRandom always return 2.
 * randomSet.getRandom();
 */

/**
 * 用hashtable能实现insert和remove用时O(1)，而随机访问可以用数组实现，所以关键是维护好hashtable与vector之间的关系，hashtable的value存储该key在vector的下标，
 * 插入和删除的时候更新hashtable同时维护该值，获取随机数的时候直接从vector中获取其中一个即可。
 */

class RandomizedSet {
    public:
        /** Initialize your data structure here. */
        RandomizedSet() {
            
        }
        
        /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val) {
            std::unordered_map<int, size_t>::const_iterator it = u.find(val);
            if (it != u.end()) {
                return false;
            }
            u[val] = v.size();
            v.push_back(val);
            return true;
        }
        
        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val) {
            std::unordered_map<int, size_t>::const_iterator it = u.find(val);
            if (it == u.end()) {
                return false;
            }
            const size_t vIndex = it->second;
            u[v[v.size() - 1]] = vIndex;
            v[vIndex] = v[v.size() - 1];
            v.pop_back();
            u.erase(it);
            return true;
        }
        
        /** Get a random element from the set. */
        int getRandom() {
            if (v.size() > 0) {
                std::random_device rd;
                size_t randNum = rd() % v.size();
                return v[randNum];
            }
        }
        
    private:
        std::unordered_map<int, size_t> u;
        std::vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
