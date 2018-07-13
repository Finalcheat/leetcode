;; 35. 搜索插入位置
;; https://leetcode-cn.com/problems/search-insert-position/description/

;; 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
;; 你可以假设数组中无重复元素。

;; 示例 1:
;; 输入: [1,3,5,6], 5
;; 输出: 2

;; 示例 2:
;; 输入: [1,3,5,6], 2
;; 输出: 1

;; 示例 3:
;; 输入: [1,3,5,6], 7
;; 输出: 4

;; 示例 4:
;; 输入: [1,3,5,6], 0
;; 输出: 0


;; Guile

(define (search-insert nums target)
  (define (search-insert-iter nums first last target)
    (if (> first last)
        first
        (let ((middle-idx (quotient (+ first last) 2)))
          (let ((middle-num (vector-ref nums middle-idx)))
            (if (< middle-num target)
                (search-insert-iter nums (+ middle-idx 1) last target)
                (search-insert-iter nums first (- last 1) target))))))
  (search-insert-iter nums 0 (- (vector-length nums) 1) target))


;; Example1 => 2
(search-insert (list->vector (list 1 3 5 6)) 5)


;; Example2 => 1
(search-insert (list->vector (list 1 3 5 6)) 2)


;; Example3 => 4
(search-insert (list->vector (list 1 3 5 6)) 7)


;; Example4 => 0
(search-insert (list->vector (list 1 3 5 6)) 0)
