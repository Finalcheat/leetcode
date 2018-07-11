;; 83. 删除排序链表中的重复元素
;; https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/

;; 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

;; 示例 1:
;; 输入: 1->1->2
;; 输出: 1->2

;; 示例 2:
;; 输入: 1->1->2->3->3
;; 输出: 1->2->3


;; Guile

(define (delete-duplicates head)
  (if (eq? head '())
      '()
      (let ((node (car head))
            (head (cdr head)))
        (cond ((eq? head '()) (cons node '()))
              ((not (= node (car head))) (cons node (delete-duplicates head)))
              (else (delete-duplicates head))))))


;; Example1 => (1 2)
(delete-duplicates (list 1 1 2))


;; Example2 => (1 2 3)
(delete-duplicates (list 1 1 2 3 3))


;; Example3 => (1 2 3 4 5)
(delete-duplicates (list 1 2 2 3 3 3 4 5 5 5 5 5 5))


;; Example4 => (1 2 3)
(delete-duplicates (list 1 2 3))
