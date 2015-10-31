import calendar

month, day, year = map(int, raw_input().split())

print calendar.day_name[calendar.weekday(year, month, day)].upper()
