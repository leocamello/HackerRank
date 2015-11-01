from dateutil import parser
from datetime import datetime, timedelta

for i in range(0, int(raw_input())):
    t1 = parser.parse(raw_input())
    t2 = parser.parse(raw_input())
    print int(abs((t1 - t2).total_seconds()))
