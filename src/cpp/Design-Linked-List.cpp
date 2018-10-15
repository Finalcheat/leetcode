/**
 * @file Design-Linked-List.cpp
 * @brief 设计链表(https://leetcode.com/problems/design-linked-list/description/)
 * @author Finalcheat
 * @date 2018-08-20
 */

/**
 * Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
 * Implement these functions in your linked list class:
 * * get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
 * * addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
 * * addAtTail(val) : Append a node of value val to the last element of the linked list.
 * * addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
 * * deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
 * Example:
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
 * linkedList.get(1);            // returns 2
 * linkedList.deleteAtIndex(1);  // now the linked list is 1->3
 * linkedList.get(1);            // returns 3
 */

/**
 * 简单设计成不带头结点的单链表就行，注意处理好头尾节点的情况就没什么难度了。
 */


class MyLinkedList {
    public:
        /** Initialize your data structure here. */
        MyLinkedList() {
            head = NULL;
            tail = NULL;
        }

        /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
        int get(int index) {
            MyLinkNode* cur = head;
            while (cur && index > 0) {
                cur = cur->next;
                --index;
            }
            if (cur) {
                return cur->val;
            }
            return -1;
        }

        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
        void addAtHead(int val) {
            MyLinkNode* node = new MyLinkNode(val);
            if (!head) {
                tail = node;
            } else {
                node->next = head;
            }
            head = node;
        }

        /** Append a node of value val to the last element of the linked list. */
        void addAtTail(int val) {
            MyLinkNode* node = new MyLinkNode(val);
            if (!tail) {
                head = node;
            } else {
                tail->next = node;
            }
            tail = node;
        }

        /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
        void addAtIndex(int index, int val) {
            if (index == 0) {
                return addAtHead(val);
            }
            MyLinkNode* cur = head;
            while (--index > 0 && cur) {
                cur = cur->next;
            }
            if (cur) {
                MyLinkNode* node = new MyLinkNode(val);
                node->next = cur->next;
                cur->next = node;
                if (!node->next) {
                    tail = node;
                }
            }
        }

        /** Delete the index-th node in the linked list, if the index is valid. */
        void deleteAtIndex(int index) {
            if (index == 0) {
                MyLinkNode* node = head;
                head = head->next;
                if (!head) {
                    tail = NULL;
                }
                delete node;
            } else {
                MyLinkNode* cur = head;
                while (--index > 0 && cur) {
                    cur = cur->next;
                }
                if (cur && cur->next) {
                    MyLinkNode* node = cur->next;
                    cur->next = node->next;
                    if (!cur->next) {
                        tail = cur;
                    }
                    delete node;
                }
            }
        }

    private:
        typedef struct MyLinkNode {
            MyLinkNode(int _v) : val(_v), next(NULL) { }
            int val;
            struct MyLinkNode* next;
        } MyLinkNode;
        MyLinkNode* head;
        MyLinkNode* tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
