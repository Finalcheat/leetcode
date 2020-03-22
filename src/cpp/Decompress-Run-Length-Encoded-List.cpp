/**
 * @file Decompress-Run-Length-Encoded-List.cpp
 * @brief 解码长度编码(https://leetcode.com/problems/decompress-run-length-encoded-list/)
 * @author Finalcheat
 * @date 2020-03-22
 */

/**
 * We are given a list nums of integers representing a list compressed with run-length encoding.
 * Consider each adjacent pair of elements [freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are freq elements with value val concatenated in a sublist. Concatenate all the sublists from left to right to generate the decompressed list.
 * Return the decompressed list.
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [2,4,4,4]
 * Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
 * The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
 * At the end the concatenation [2] + [4,4,4] is [2,4,4,4].
 * Example 2:
 * Input: nums = [1,1,2,3]
 * Output: [1,3,3]
 */

/**
 * 按规则解码即可。
 */

class Solution {
    public:
	vector<int> decompressRLElist(vector<int>& nums) {
	    assert(nums.size() % 2 == 0);
	    vector<int> result;
	    for (size_t i = 0; i < nums.size(); i += 2) {
		const int freq = nums[i];
		const int val = nums[i + 1];
		result.resize(freq + result.size(), val);
	    }
	    return result;
	}
};
