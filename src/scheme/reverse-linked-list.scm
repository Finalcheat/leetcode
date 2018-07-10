;; 206. 反转链表
;; https://leetcode-cn.com/problems/reverse-linked-list/description/

;; 反转一个单链表。

;; 示例:
;; 输入: 1->2->3->4->5->NULL
;; 输出: 5->4->3->2->1->NULL


;; Guile

(define (reverse-list head)
  (if (eq? head '())
      '()
      (append (reverse-list (cdr head)) (list (car head)))))


;; Example1 => (5 4 3 2 1)
(reverse-list (list 1 2 3 4 5))
