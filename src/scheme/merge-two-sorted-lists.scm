;; 21. 合并两个有序链表
;; https://leetcode-cn.com/problems/merge-two-sorted-lists/description/

;; 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

;; 示例：
;; 输入：1->2->4, 1->3->4
;; 输出：1->1->2->3->4->4


;; Guile

(define (merge-two-lists l1 l2)
  (cond ((eq? l1 '()) l2)
        ((eq? l2 '()) l1)
        (else (let ((num1 (car l1))
                    (num2 (car l2)))
                (if (< num1 num2)
                    (cons num1 (merge-two-lists (cdr l1) l2))
                    (cons num2 (merge-two-lists l1 (cdr l2))))))))


;; Example1 => (1 1 2 3 4 4)
(merge-two-lists (list 1 2 4) (list 1 3 4))

;; Example2 => (1 2 3 4 5 6)
(merge-two-lists (list 1 2 3) (list 4 5 6))

;; Example3 => (0 1 2 4 5 6)
(merge-two-lists (list 4 5 6) (list 0 1 2))
