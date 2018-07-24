;; 283. 移动零
;; https://leetcode-cn.com/problems/move-zeroes/description/

;; 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

;; 示例:
;; 输入: [0,1,0,3,12]
;; 输出: [1,3,12,0,0]

;; 说明:
;; 1. 必须在原数组上操作，不能拷贝额外的数组。
;; 2. 尽量减少操作次数。


;; Guile

(define (move-zeroes nums)
  (define (memset-zeroes-iter nums first last)
    (if (< first last)
        (begin (vector-set! nums first 0)
               (memset-zeroes-iter nums (+ first 1) last))
        nums))
  (define (move-zeroes-iter nums idx zero-idx)
    (if (< idx (vector-length nums))
        (let ((num (vector-ref nums idx))
              (idx (+ idx 1)))
          (if (= num 0)
              (move-zeroes-iter nums idx zero-idx)
              (begin (vector-set! nums zero-idx num)
                     (move-zeroes-iter nums idx (+ zero-idx 1)))))
        ;; (memset-zeroes-iter nums zero-idx idx)))
        zero-idx))
  (memset-zeroes-iter nums (move-zeroes-iter nums 0 0) (vector-length nums)))
  ;; (move-zeroes-iter nums 0 0))


;; Example1 => #(1 3 12 0 0)
(move-zeroes (list->vector (list 0 1 0 3 12)))
