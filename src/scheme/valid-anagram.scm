;; 242. 有效的字母异位词
;; https://leetcode-cn.com/problems/valid-anagram/description/

;; 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

;; 示例 1:
;; 输入: s = "anagram", t = "nagaram"
;; 输出: true

;; 示例 2:
;; 输入: s = "rat", t = "car"
;; 输出: false


;; Guile

(define (is-anagram s t)
  (define (is-anagram-iter s t idx)
    (if (< idx (string-length s))
        (cond ((eq? (string-ref s idx) (string-ref t idx)) (is-anagram-iter s t (+ idx 1)))
              (else #f))
        #t))
  (is-anagram-iter (sort s char<?) (sort t char<?) 0))


;; Example1 => #t
(is-anagram "anagram" "nagaram")


;; Example2 => #f
(is-anagram "rat" "car")
