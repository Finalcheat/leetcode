;; 383. 赎金信
;; https://leetcode-cn.com/problems/ransom-note/description/

;; 给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。
;; (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)

;; 注意：
;; 你可以假设两个字符串均只含有小写字母。
;; canConstruct("a", "b") -> false
;; canConstruct("aa", "ab") -> false
;; canConstruct("aa", "aab") -> true


;; Guile

(define (can-construct ransom-note magazine)
  (define (build-h magazine)
    (define h (make-hash-table 50))
    (define (build-h-iter magazine idx)
      (if (= idx (string-length magazine))
          h
          (let ((c (string-ref magazine idx))
                (idx (+ idx 1)))
            (let ((find (hash-ref h c)))
              (cond ((eq? find #f) (begin (hash-set! h c 1) (build-h-iter magazine idx)))
                    (else (begin (hash-set! h c (+ find 1)) (build-h-iter magazine idx))))))))
    (build-h-iter magazine 0))
  (define (can-construct-iter ransom-note idx h)
    (if (= idx (string-length ransom-note))
        #t
        (let ((c (string-ref ransom-note idx))
              (idx (+ idx 1)))
          (let ((find (hash-ref h c)))
            (cond ((or (eq? find #f) (= find 0)) #f)
                  (else (begin (hash-set! h c (- find 1)) (can-construct-iter ransom-note idx h))))))))
  (can-construct-iter ransom-note 0 (build-h magazine)))


;; Example1 => #f
(can-construct "a" "b")


;; Example2 => #f
(can-construct "aa" "ab")


;; Example3 => #t
(can-construct "aa" "aab")
