def full_name(first, *middle, last)
    name = first
    middle.each do |m|
        name = name + " " + m
    end
    name = name + " " + last
    return name
end
