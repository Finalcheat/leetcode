;; 494. 目标和
;; https://leetcode-cn.com/problems/target-sum/description/

;; 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。
;; 对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
;; 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

;; 示例 1:
;; 输入: nums: [1, 1, 1, 1, 1], S: 3
;; 输出: 5
;; 解释:
;; -1+1+1+1+1 = 3
;; +1-1+1+1+1 = 3
;; +1+1-1+1+1 = 3
;; +1+1+1-1+1 = 3
;; +1+1+1+1-1 = 3
;; 一共有5种方法让最终目标和为3。


;; Guile

(define (find-target-sum-ways nums S)
  (if (eq? nums '())
      (if (= S 0)
          1
          0)
      (let ((num1 (+ S (car nums)))
            (num2 (- S (car nums))))
        (+ (find-target-sum-ways (cdr nums) num1)
           (find-target-sum-ways (cdr nums) num2)))))


;; Example1 => 5
(find-target-sum-ways (list 1 1 1 1 1) 3)

;; Example2 => 1
(find-target-sum-ways (list 1 2 3 4 5) 15)

