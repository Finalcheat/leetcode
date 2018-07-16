;; 53. 最大子序和
;; https://leetcode-cn.com/problems/maximum-subarray/description/

;; 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

;; 示例:
;; 输入: [-2,1,-3,4,-1,2,1,-5,4],
;; 输出: 6
;; 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。


;; Guile

(define (max-sub-array nums)
  (define (max-sub-array-iter nums result sum)
    (if (eq? nums '())
        result
        (let ((sum (+ sum (car nums)))
              (nums (cdr nums)))
          (let ((result (max sum result)))
            (if (< sum 0)
                (max-sub-array-iter nums result 0)
                (max-sub-array-iter nums result sum))))))
  (if (eq? nums '())
      0
      (let ((first-num (car nums))
            (nums (cdr nums)))
        (max-sub-array-iter nums first-num first-num))))


;; Example1 => 6
(max-sub-array (list (- 2) 1 (- 3) 4 (- 1) 2 1 (- 5) 4))
