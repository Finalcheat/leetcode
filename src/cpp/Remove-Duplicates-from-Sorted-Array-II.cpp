/**
 * @file Remove-Duplicates-from-Sorted-Array-II.cpp
 * @brief 从已排序的数组中删除重复的元素II(https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)
 * @author Finalcheat
 * @date 2016-05-08
 */

/**
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 */

/**
 * 删除元素出现次数大于2的元素，可以换个思路，将原数组的元素拷贝过来，当且仅当当前元素等于“新数组”的前两个元素时不作操作，其他情况拷贝元素值即可。
 */

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() < 3) {
                return nums.size();
            }
            int index = 2;
            for (size_t i = 2; i < nums.size(); ++i) {
                int num = nums[i];
                if (num == nums[index - 1] && nums[index - 1] == nums[index - 2]) {
                    continue;
                }
                nums[index] = num;
                ++index;
            }
            return index;
        }
};
