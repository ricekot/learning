(define (fast-expt b n)
  (define (square n)
    (* n n))
  (define (iter a b n)
    (cond ((= n 0) a)
      ((even? n) (iter a (square b) (/ n 2)))
      (else (iter (* a b) (square b) (/ (- n 1) 2)))))
  (iter 1 b n))
