/**
 * @file Create-Target-Array-in-the-Given-Order.cpp
 * @brief 按照给定的顺序创建目标数组(https://leetcode.com/problems/create-target-array-in-the-given-order/)
 * @author Finalcheat
 * @date 2020-03-30
 */

/**
 * Given two arrays of integers nums and index. Your task is to create target array under the following rules:
 * * Initially target array is empty.
 * * From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
 * * Repeat the previous step until there are no elements to read in nums and index.
 * Return the target array.
 * It is guaranteed that the insertion operations will be valid.
 * Example 1:
 * Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
 * Output: [0,4,1,3,2]
 * Explanation:
 * nums       index     target
 * 0            0        [0]
 * 1            1        [0,1]
 * 2            2        [0,1,2]
 * 3            2        [0,1,3,2]
 * 4            1        [0,4,1,3,2]
 * Example 2:
 * Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
 * Output: [0,1,2,3,4]
 * Explanation:
 * nums       index     target
 * 1            0        [1]
 * 2            1        [1,2]
 * 3            2        [1,2,3]
 * 4            3        [1,2,3,4]
 * 0            0        [0,1,2,3,4]
 * Example 3:
 * Input: nums = [1], index = [0]
 * Output: [1]
 */

/**
 * 直接用vector的insert就行了，没什么难度。
 */

class Solution {
    public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
	    assert(nums.size() == index.size());
	    vector<int> result;
	    for (size_t i = 0; i < nums.size(); ++i) {
		vector<int>::iterator position = result.begin() + index[i];
		result.insert(position, nums[i]);
	    }
	    return result;
	}
};
