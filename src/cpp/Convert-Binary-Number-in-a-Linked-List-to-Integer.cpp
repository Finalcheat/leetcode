/**
 * @file Convert-Binary-Number-in-a-Linked-List-to-Integer.cpp
 * @brief 将链表中的二进制数转换为十进制数(https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)
 * @author Finalcheat
 * @date 2020-04-16
 */

/**
 * Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
 * Return the decimal value of the number in the linked list.
 * Example 1:
 * 1 -> 0 -> 1
 * Input: head = [1,0,1]
 * Output: 5
 * Explanation: (101) in base 2 = (5) in base 10
 * Example 2:
 * Input: head = [0]
 * Output: 0
 * Example 3:
 * Input: head = [1]
 * Output: 1
 * Example 4:
 * Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
 * Output: 18880
 * Example 5:
 * Input: head = [0,0]
 * Output: 0
 */

/**
 * 按照二进制规则左移相加转成十进制。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        int getDecimalValue(ListNode* head) {
            int decimalValue = 0;
            for (ListNode* curNode = head; curNode != NULL; curNode = curNode->next) {
                decimalValue <<= 1;
                decimalValue |= curNode->val;
            }
            return decimalValue;
        }
};
