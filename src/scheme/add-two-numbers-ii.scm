;; 445. 两数相加 II
;; https://leetcode-cn.com/problems/add-two-numbers-ii/description/

;; 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
;; 你可以假设除了数字 0 之外，这两个数字都不会以零开头。

;; 示例:
;; 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
;; 输出: 7 -> 8 -> 0 -> 7


;; Guile

(define (add-two-numbers l1 l2)
  (define v1 (list->vector l1))
  (define idx1 (- (vector-length v1) 1))
  (define v2 (list->vector l2))
  (define idx2 (- (vector-length v2) 1))
  (define carry 0)
  (define (get-v-num v idx)
    (if (< idx 0)
        0
        (vector-ref v idx)))
  (define (add-two-numbers-iter v1 idx1 v2 idx2 carry)
    (if (and (< idx1 0) (< idx2 0) (= carry 0))
        '()
        (let ((num1 (get-v-num v1 idx1))
              (num2 (get-v-num v2 idx2))
              (idx1 (- idx1 1))
              (idx2 (- idx2 1)))
          (let ((sum (+ num1 num2 carry)))
            (cons (remainder sum 10) (add-two-numbers-iter v1 idx1 v2 idx2 (quotient sum 10)))))))
  (reverse (add-two-numbers-iter v1 idx1 v2 idx2 carry)))


;; Example1 => (7 8 0 7)
(add-two-numbers (list 7 2 4 3) (list 5 6 4))
