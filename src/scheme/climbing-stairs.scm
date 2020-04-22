;; 70. 爬楼梯
;; https://leetcode-cn.com/problems/climbing-stairs/description/

;; 假设你正在爬楼梯。需要 n 步你才能到达楼顶。
;; 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
;; 注意：给定 n 是一个正整数。

;; 示例 1：
;; 输入： 2
;; 输出： 2
;; 解释： 有两种方法可以爬到楼顶。
;; 1.  1 步 + 1 步
;; 2.  2 步

;; 示例 2：
;; 输入： 3
;; 输出： 3
;; 解释： 有三种方法可以爬到楼顶。
;; 1.  1 步 + 1 步 + 1 步
;; 2.  1 步 + 2 步
;; 3.  2 步 + 1 步


;; Guile

(define (climb-stairs n)
  (define (climb-stairs-iter a b c n)
    (if (> n 0)
        (climb-stairs-iter c a (+ b c) (- n 1))
        c))
  (if (< n 4)
      n
      (climb-stairs-iter 2 3 5 (- n 4))))


;; Example1 => 2
(climb-stairs 2)


;; Example2 => 3
(climb-stairs 3)


;; Example3 => 8
(climb-stairs 5)
