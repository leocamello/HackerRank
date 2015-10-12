def end_arr_add(arr, element)
    return arr.push(element)
end

def begin_arr_add(arr, element)
    return arr.unshift(element)
end

def index_arr_add(arr, index, element)
    return arr.insert(index, element)
end

def index_arr_multiple_add(arr, index)
    return arr.insert(index, 10, 20)
end
