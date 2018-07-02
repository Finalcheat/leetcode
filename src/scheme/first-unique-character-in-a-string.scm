;; 387. 字符串中的第一个唯一字符
;; https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/

;; 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

;; 案例:
;; s = "leetcode"
;; 返回 0.
;; s = "loveleetcode",
;; 返回 2.


;; Guile

(define (first-uniq-char s)
  (define (init-hash s)
    (define h (make-hash-table 26))
    (define (init-hash-iter s idx)
      (if (< idx (string-length s))
          (let ((find (hash-ref h (string-ref s idx)))
                (c (string-ref s idx)))
            (cond ((eq? find #f) (begin (hash-set! h c 1) (init-hash-iter s (+ idx 1))))
                  (else (begin (hash-set! h c (+ find 1)) (init-hash-iter s (+ idx 1))))))
          h))
    (init-hash-iter s 0))
  (define (first-uniq-char-iter s idx h)
    (if (< idx (string-length s))
        (let ((find (hash-ref h (string-ref s idx)))
              (c (string-ref s idx)))
          (cond ((eq? find #f) -1)
                ((= find 1) idx)
                (else (first-uniq-char-iter s (+ idx 1) h))))
        -1))
  (first-uniq-char-iter s 0 (init-hash s)))


;; Example1 => 0
(first-uniq-char "leetcode")


;; Example2 => 2
(first-uniq-char "loveleetcode")
