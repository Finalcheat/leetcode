;; 520. 检测大写字母
;; https://leetcode-cn.com/problems/detect-capital/description/

;; 给定一个单词，你需要判断单词的大写使用是否正确。
;; 我们定义，在以下情况时，单词的大写用法是正确的：
;; 1. 全部字母都是大写，比如"USA"。
;; 2. 单词中所有字母都不是大写，比如"leetcode"。
;; 3. 如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
;; 否则，我们定义这个单词没有正确使用大写字母。

;; 示例 1:
;; 输入: "USA"
;; 输出: True

;; 示例 2:
;; 输入: "FlaG"
;; 输出: False


;; Guile

(define (detect-capital-use word)
  (define (detect-capital-use-iter word idx status)
    (if (= idx (string-length word))
        #t
        (let ((c (char->integer (string-ref word idx)))
              (idx (+ idx 1)))
          (cond ((= status 0) (if (or (< c (char->integer #\A)) (> c (char->integer #\Z)))
                                  (detect-capital-use-iter word idx 2)
                                  (detect-capital-use-iter word idx 1)))
                ((= status 1) (if (or (< c (char->integer #\A) (> c (char->integer #\Z))))
                                  (detect-capital-use-iter word idx 2)
                                  (detect-capital-use-iter word idx 3)))
                ((= status 2) (if (and (> c (- (char->integer #\A) 1)) (< c (+ (char->integer #\Z) 1)))
                                  #f
                                  (detect-capital-use-iter word idx 2)))
                (else (if (and (> c (- (char->integer #\a) 1)) (< c (+ (char->integer #\z) 1)))
                          #f
                          (detect-capital-use-iter word idx 3)))))))
  (detect-capital-use-iter word 0 0))


;; Example1 => #t
(detect-capital-use "USA")


;; Example2 => #f
(detect-capital-use "FlaG")
