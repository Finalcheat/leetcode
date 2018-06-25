;; 824. 山羊拉丁文
;; https://leetcode-cn.com/problems/goat-latin/description/

;; 给定一个由空格分割单词的句子 S。每个单词只包含大写或小写字母。
;; 我们要将句子转换为 “Goat Latin”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。
;; 山羊拉丁文的规则如下：
;; * 如果单词以元音开头（a, e, i, o, u），在单词后添加"ma"。
;;   例如，单词"apple"变为"applema"。
;; * 如果单词以辅音字母开头（即非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
;;   例如，单词"goat"变为"oatgma"。
;; * 根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从1开始。
;;   例如，在第一个单词后添加"a"，在第二个单词后添加"aa"，以此类推。
;; 返回将 S 转换为山羊拉丁文后的句子。

;; 示例 1:
;; 输入: "I speak Goat Latin"
;; 输出: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

;; 示例 2:
;; 输入: "The quick brown fox jumped over the lazy dog"
;; 输出: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"


;; Guile

(define (to-goat-latin S)
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
  (define (to-goat-latin-iter words idx)
    (if (eq? words '())
        '()
        (let ((word (car words))
              (words (cdr words))
              (idx (+ idx 1)))
          (let ((first-char (string-ref word 0))
                (a-repeat (make-string idx #\a))
                (ma "ma"))
            (if (eq? (is-vowel first-char) #t)
                (cons (string-append word ma a-repeat) (to-goat-latin-iter words idx))
                (cons (string-append (substring word 1) (make-string 1 first-char) ma a-repeat)
                      (to-goat-latin-iter words idx)))))))
  (string-join (to-goat-latin-iter (string-split S #\space) 0) " "))


;; Example1 => "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
(to-goat-latin "I speak Goat Latin")


;; Example2 => "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
(to-goat-latin "The quick brown fox jumped over the lazy dog")
