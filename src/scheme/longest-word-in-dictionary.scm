;; 720. 词典中最长的单词
;; https://leetcode-cn.com/problems/longest-word-in-dictionary/description/

;; 给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。
;; 若其中有多个可行的答案，则返回答案中字典序最小的单词。
;; 若无答案，则返回空字符串。

;; 示例 1:
;; 输入:
;; words = ["w","wo","wor","worl", "world"]
;; 输出: "world"
;; 解释:
;; 单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。

;; 示例 2:
;; 输入:
;; words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
;; 输出: "apple"
;; 解释:
;; "apply"和"apple"都能由词典中的单词组成。但是"apple"得字典序小于"apply"。


;; Guile

(define (longest-word words)
  (define (longest-word-iter words h result)
    (if (eq? words '())
        result
        (let ((word (car words))
              (words (cdr words)))
          (let ((pre-word (substring word 0 (- (string-length word) 1))))
            (if (or (= 0 (string-length pre-word)) (not (eq? (hash-ref h pre-word) #f)))
                (begin (hash-set! h word #t)
                       (if (> (string-length word) (string-length result))
                           (longest-word-iter words h word)
                           (longest-word-iter words h result)))
                (longest-word-iter words h result))))))
  (longest-word-iter (sort-list words string<?) (make-hash-table 50) ""))


;; Example1 => "world"
(longest-word (list "w" "wo" "wor" "worl" "world"))


;; Example2 => "apple"
(longest-word (list "a" "banana" "app" "appl" "ap" "apply" "apple"))
