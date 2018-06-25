;; 561. 数组拆分I
;; https://leetcode-cn.com/problems/array-partition-i/description/

;; 给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，
;; 使得从1 到 n 的 min(ai, bi) 总和最大。

;; 示例 1:
;; 输入: [1,4,3,2]
;; 输出: 4
;; 解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).


;; Guile

(define (array-pair-sum nums)
  (define (array-pair-sum-iter sort-nums idx sum)
    (if (not (< idx (vector-length sort-nums)))
        sum
        (array-pair-sum-iter sort-nums (+ idx 2) (+ sum (let ((num1 (vector-ref sort-nums idx))
                                                              (num2 (vector-ref sort-nums (+ idx 1))))
                                                          (if (< num1 num2)
                                                              num1
                                                              num2))))))
  (array-pair-sum-iter (sort nums <) 0 0))


;; Example1 => 4
(array-pair-sum (list->vector (list 1 4 3 2)))

