def process_text(string_array)
    string = ""
    string_array.each { |s|
        string = string + s.strip + " "
        }
    return string.strip
end
