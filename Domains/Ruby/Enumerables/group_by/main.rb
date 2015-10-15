def group_by_marks(marks, n)
    marks.group_by do |key, value|
        if key.empty? == false
            if value >= n
                "Passed"
            else
                "Failed"
            end
        end
    end
end
