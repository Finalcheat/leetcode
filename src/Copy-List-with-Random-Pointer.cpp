/**
 * @file Copy-List-with-Random-Pointer.cpp
 * @brief 深拷贝链表(https://leetcode.com/problems/copy-list-with-random-pointer/)
 * @author Finalcheat
 * @date 2017-04-11
 */

/**
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 */

/**
 * 深拷贝只要遍历重新分配内存赋值即可，难点在于有一个随机指针指向另一节点，这就涉及到去重的问题了，用hash table就行了。
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            RandomListNode* newHead = NULL;
            RandomListNode* newTail = NULL;
            std::unordered_map<RandomListNode*, RandomListNode*> u;
            for (RandomListNode* node = head; node != NULL; node = node->next) {
                auto it = u.find(node);
                RandomListNode* newNode;
                if (it == u.end()) {
                    newNode = new RandomListNode(node->label);
                } else {
                    newNode = it->second;
                }
                u[node] = newNode;
                
                if (node->random) {
                    it = u.find(node->random);
                    if (it != u.end()) {
                        newNode->random = it->second;
                    } else {
                        RandomListNode* newRandomNode = new RandomListNode(node->random->label);
                        u[node->random] = newRandomNode;
                        newNode->random = newRandomNode;
                    }
                }
                
                if (newTail) {
                    newTail->next = newNode;
                    newTail = newNode;
                } else {
                    newHead = newNode;
                    newTail = newNode;
                }
            }
            return newHead;
        }
};
