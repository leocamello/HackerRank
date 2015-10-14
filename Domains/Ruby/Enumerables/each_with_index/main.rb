def skip_animals(animals, skip)
    array = Array.new
    animals.each_with_index do |animal, index|
        unless index < skip
            array.push("#{index}:#{animal}")
        end
    end
    return array
end
