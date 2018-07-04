;; 234. 回文链表
;; https://leetcode-cn.com/problems/palindrome-linked-list/description/

;; 请判断一个链表是否为回文链表。

;; 示例 1:
;; 输入: 1->2
;; 输出: false

;; 示例 2:
;; 输入: 1->2->2->1
;; 输出: true


;; Guile

(define (is-palindrome head)
  (define (is-palindrome-iter head v idx)
    (if (eq? head '())
        #t
        (cond ((= (car head) (vector-ref v idx)) (is-palindrome-iter (cdr head) v (- idx 1)))
              (else #f))))
  (define v (list->vector head))
  (is-palindrome-iter head v (- (vector-length v) 1)))


;; Example1 => #f
(is-palindrome (list 1 2))


;; Example2 => #t
(is-palindrome (list 1 2 2 1))


;; Example3 => #t
(is-palindrome (list 1 2 3 2 1))
