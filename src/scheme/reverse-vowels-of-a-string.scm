;; 345. 反转字符串中的元音字母
;; https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/

;; 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

;; 示例 1：
;; 给定 s = "hello", 返回 "holle".

;; 示例 2：
;; 给定 s = "leetcode", 返回 "leotcede".

;; 注意:
;; 元音字母不包括 "y".


;; Guile

(define (reverse-vowels s)
  (define (is-vowel c)
    (cond ((eq? c #\a) #t)
          ((eq? c #\A) #t)
          ((eq? c #\e) #t)
          ((eq? c #\E) #t)
          ((eq? c #\i) #t)
          ((eq? c #\I) #t)
          ((eq? c #\o) #t)
          ((eq? c #\O) #t)
          ((eq? c #\u) #t)
          ((eq? c #\U) #t)
          (else #f)))
  (define (swap-vowel s first last)
    (let ((tmp (string-ref s first)))
      (begin (string-set! s first (string-ref s last)) (string-set! s last tmp))))
  (define (reverse-vowels-iter s first last)
    (if (< first last)
        (let ((fc (string-ref s first))
              (lc (string-ref s last)))
          (cond ((eq? (is-vowel fc) #f) (reverse-vowels-iter s (+ first 1) last))
                ((eq? (is-vowel lc) #f) (reverse-vowels-iter s first (- last 1)))
                (else (begin (swap-vowel s first last)
                             (reverse-vowels-iter s (+ first 1) (- last 1))))))
        s))
  (reverse-vowels-iter s 0 (- (string-length s) 1)))


;; Example1 => "holle"
(reverse-vowels (string-append "hello"))


;; Example2 => "leotcede"
(reverse-vowels (string-append "leetcode"))

