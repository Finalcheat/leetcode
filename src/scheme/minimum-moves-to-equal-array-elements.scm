;; 453. 最小移动次数使数组元素相等
;; https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/description/

;; 给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。

;; 示例:
;; 输入:
;; [1,2,3]
;; 输出:
;; 3
;; 解释:
;; 只需要3次移动（注意每次移动会增加两个元素的值）：
;; [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]


;; Guile

(define (min-moves nums)
  (define (find-min-num nums)
    (define (find-min-num-iter nums min-num)
      (if (eq? nums '())
          min-num
          (let ((num (car nums))
                (nums (cdr nums)))
            (if (< num min-num)
                (find-min-num-iter nums num)
                (find-min-num-iter nums min-num)))))
    (if (eq? nums '())
        0
        (find-min-num-iter (cdr nums) (car nums))))
  (define (min-moves-iter nums min-num result)
    (if (eq? nums '())
        result
        (min-moves-iter (cdr nums) min-num (+ result (- (car nums) min-num)))))
  (min-moves-iter nums (find-min-num nums) 0))


;; Example1 => 3
(min-moves (list 1 2 3))
