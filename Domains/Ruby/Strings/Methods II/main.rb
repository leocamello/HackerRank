def mask_article(string, words)
    words.each { |word|
        if string.include?(word)
            string = string.gsub(word, strike(word))
        end
    }
    return string
end

def strike(string)
    return "<strike>" + string + "</strike>"
end
