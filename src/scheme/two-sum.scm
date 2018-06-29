;; 1. 两数之和
;; https://leetcode-cn.com/problems/two-sum/description/

;; 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
;; 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

;; 示例:
;; 给定 nums = [2, 7, 11, 15], target = 9
;; 因为 nums[0] + nums[1] = 2 + 7 = 9
;; 所以返回 [0, 1]


;; Guile

(define (two-sum nums target)
  (define (init-hash nums idx h)
    (if (< idx (vector-length nums))
        (begin (hash-set! h (vector-ref nums idx) idx)
               (init-hash nums (+ idx 1) h))
        h))
  (define (two-sum-iter nums idx h target)
    (if (< idx (vector-length nums))
        (let ((value (- target (vector-ref nums idx))))
          (let ((find (hash-ref h value)))
            (if (and (not (eq? find #f)) (not (= find idx)))
                (cons idx find)
                (two-sum-iter nums (+ idx 1) h target))))
        '()))
  (two-sum-iter nums 0 (init-hash nums 0 (make-hash-table (vector-length nums))) target))


;; Example1 => (0 . 1)
(two-sum (list->vector (list 2 7 11 15)) 9)


;; Example2 => (1 . 4)
(two-sum (list->vector (list 2 8 5 6 9 7)) 17)
