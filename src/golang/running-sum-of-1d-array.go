/**
 * @file running-sum-of-1d-array.go
 * @brief 一维数组的和数组(https://leetcode.com/problems/running-sum-of-1d-array/)
 * @author Finalcheat
 * @date 2020-10-26
 */

/**
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 * Return the running sum of nums.
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [1,3,6,10]
 * Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
 * Example 2:
 * Input: nums = [1,1,1,1,1]
 * Output: [1,2,3,4,5]
 * Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
 * Example 3:
 * Input: nums = [3,1,2,10,1]
 * Output: [3,4,6,16,17]
 * Constraints:
 * * 1 <= nums.length <= 1000
 * * -10^6 <= nums[i] <= 10^6
 */

/**
 * 循环过程中记录累加值即可。
 */

func runningSum(nums []int) []int {
    curSum := 0
    for idx, value := range nums {
        curSum += value
        nums[idx] = curSum
    }
    return nums
}
