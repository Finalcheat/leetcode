;; 205. 同构字符串
;; https://leetcode-cn.com/problems/isomorphic-strings/description/

;; 给定两个字符串 s 和 t，判断它们是否是同构的。
;; 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
;; 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

;; 示例 1:
;; 输入: s = "egg", t = "add"
;; 输出: true

;; 示例 2:
;; 输入: s = "foo", t = "bar"
;; 输出: false

;; 示例 3:
;; 输入: s = "paper", t = "title"
;; 输出: true


;; Guile

(define (is-isomorphic s t)
  (define (hash-value h c idx)
    (let ((find (hash-ref h c)))
      (begin (hashq-set! h c idx) find)))
  (define (is-isomorphic-iter s t idx h1 h2)
    (if (not (< idx (string-length s)))
        #t
        (let ((sc (string-ref s idx))
              (tc (string-ref t idx))
              (idx (+ idx 1)))
          (if (not (eq? (hash-value h1 sc idx) (hash-value h2 tc idx)))
              #f
              (is-isomorphic-iter s t idx h1 h2)))))
  (is-isomorphic-iter s t 0 (make-hash-table (string-length s)) (make-hash-table (string-length t))))


;; Example1 => #t
(is-isomorphic "egg" "add")


;; Example2 => #f
(is-isomorphic "foo" "bar")


;; Example3 => #t
(is-isomorphic "paper" "title")
