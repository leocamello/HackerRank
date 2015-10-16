def convert_temp(input, input_scale: 'celsius', output_scale: 'celsius')
    if input_scale == 'celsius' and output_scale == 'kelvin'
        return input + 273.15
    elsif input_scale == 'celsius' and output_scale == 'fahrenheit'
        return ((input / 5) * 9) + 32.0
    elsif input_scale == 'kelvin' and output_scale == 'celsius'
        return input - 273.15
    elsif input_scale == 'kelvin' and output_scale == 'fahrenheit'
        return (((input - 273.15) / 5) * 9) + 32.0
    elsif input_scale == 'fahrenheit' and output_scale == 'celsius'
        return ((input - 32.0) / 9) * 5
    elsif input_scale == 'fahrenheit' and output_scale == 'kelvin'
        return (((input - 32.0) / 9) * 5) + 273.15
    else
        return input
    end
end
