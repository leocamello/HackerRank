def serial_average(string)
    serial = string[0, 3]
    x, y = string[4, 5], string[10, 5]
    average = ((x.to_f + y.to_f) / 2.0)
    return "#{serial}-%.2f" % average
end
