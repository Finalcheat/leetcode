;; 575. 分糖果
;; https://leetcode-cn.com/problems/distribute-candies/description/

;; 给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。

;; 示例 1:
;; 输入: candies = [1,1,2,2,3,3]
;; 输出: 3
;; 解析: 一共有三种种类的糖果，每一种都有两个。
;; 最优分配方案：妹妹获得[1,2,3],弟弟也获得[1,2,3]。这样使妹妹获得糖果的种类数最多。

;; 示例 2 :
;; 输入: candies = [1,1,2,3]
;; 输出: 2
;; 解析: 妹妹获得糖果[2,3],弟弟获得糖果[1,1]，妹妹有两种不同的糖果，弟弟只有一种。这样使得妹妹可以获得的糖果种类数最多。


;; Guile

(define (distribute-candies candies)
  (define (candies-category-count h candies count size)
    (if (eq? candies '())
        (cons size count)
        (if (not (eq? (hash-ref h (car candies)) #f))
            (candies-category-count h (cdr candies) count (+ size 1))
            (begin (hash-set! h (car candies) #t)
                   (candies-category-count h (cdr candies) (+ count 1) (+ size 1))))))
  (define res (candies-category-count (make-hash-table 50) candies 0 0))
  (min (quotient (car res) 2) (cdr res)))


;; Example1 => 3
(distribute-candies (list 1 1 2 2 3 3))


;; Example2 => 2
(distribute-candies (list 1 1 2 3))
