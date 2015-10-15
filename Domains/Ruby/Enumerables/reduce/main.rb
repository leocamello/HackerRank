def sum_terms(n)
    (1..n).reduce(0) {|sum, n| sum + (n * n) + 1}
end
