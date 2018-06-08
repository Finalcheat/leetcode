;; 771. 宝石与石头
;; https://leetcode-cn.com/problems/jewels-and-stones/description/

;; 给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。
;; S中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
;; J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。

;; 示例 1:
;; 输入: J = "aA", S = "aAAbbbb"
;; 输出: 3

;; 示例 2:
;; 输入: J = "z", S = "ZZ"
;; 输出: 0

;; 注意:
;; S 和 J 最多含有50个字母。
;; J 中的字符不重复。


;; Guile

(define (numJewelsInStones J S)
  (define (init-jewels-hash-table J)
    (define h (make-hash-table 50))
    (define J-len (string-length J))
    (define (init-jewels-hash-table-iter h J idx)
      (if (>= idx 0)
          (begin (hashq-set! h (string-ref J idx) #t)
                 (init-jewels-hash-table-iter h J (- idx 1)))
          h))
    (init-jewels-hash-table-iter h J (- J-len 1)))
  (define (find-jewels h S)
    (define (find-jewels-iter h S idx counter)
      (if (< idx 0)
          counter
          (if (eq? (hashq-ref h (string-ref S idx)) #t)
              (find-jewels-iter h S (- idx 1) (+ counter 1))
              (find-jewels-iter h S (- idx 1) counter))))
    (find-jewels-iter h S (- (string-length S) 1) 0))
  (find-jewels (init-jewels-hash-table J) S))


;; 3
(numJewelsInStones "aA" "aAAbbbb")


;; 0
(numJewelsInStones "z" "ZZ")



