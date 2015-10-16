def prime?(n)
    if n <= 1
        return false
    elsif n <= 3
        return true
    elsif n % 2 == 0 or n % 3 == 0
        return false
    end

    i = 5

    loop do
        if i * i <= n
            if n % i == 0 or n % (i + 2) == 0
                return false
            end
            i = i + 6
        else
            break
        end
    end

    return true
end
