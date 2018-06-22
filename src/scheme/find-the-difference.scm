;; 389. 找不同
;; https://leetcode-cn.com/problems/find-the-difference/description/

;; 给定两个字符串 s 和 t，它们只包含小写字母。
;; 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
;; 请找出在 t 中被添加的字母。

;; 示例:
;; 输入：
;; s = "abcd"
;; t = "abcde"
;; 输出：
;; e
;; 解释：
;; 'e' 是那个被添加的字母。


;; Guile

(define (find-the-difference s t)
  (define (make-hash-table-by-s s)
    (define h (make-hash-table 26))
    (define (make-hash-table-by-s-iter s idx)
      (if (< idx (string-length s))
          (let ((c (string-ref s idx))
                (idx (+ idx 1)))
            (let ((find (hash-ref h c)))
              (if (eq? find #f)
                  (begin (hash-set! h c 1)
                         (make-hash-table-by-s-iter s idx))
                  (begin (hash-set! h c (+ find 1))
                         (make-hash-table-by-s-iter s idx)))))
          h))
    (make-hash-table-by-s-iter s 0))
  (define (find-the-difference-iter h t idx)
    (if (not (< idx (string-length t)))
        "not found!"
        (let ((c (string-ref t idx))
              (idx (+ idx 1)))
          (let ((find (hash-ref h c)))
            (cond ((eq? find #f) c)
                  ((= find 0) c)
                  (else (begin (hash-set! h c (- find 1))
                               (find-the-difference-iter h t idx))))))))
  (find-the-difference-iter (make-hash-table-by-s s) t 0))


;; Example1 => #\e
(find-the-difference "abcd" "abcde")

;; Example2 => #\b
(find-the-difference "aecd" "cdbea")

;; Example3 => "not found"
(find-the-difference "aebcd" "cdbea")

;; Example4 => #\c
(find-the-difference "aebcdabcd" "cdbeadbcac")
