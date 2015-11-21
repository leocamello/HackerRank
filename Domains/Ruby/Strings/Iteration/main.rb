def count_multibyte_char(string)
    count = 0
    string.each_char { |c|
        if c.bytesize() > 1
            count = count + 1
        end
    }
    return count
end
