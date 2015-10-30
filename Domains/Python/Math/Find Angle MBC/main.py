import math
import cmath

AC = complex(int(raw_input()), int(raw_input()))

angle = 90.0 - math.degrees(cmath.phase(AC / 2))

if angle < 0.5:
    print "0°"
elif angle < 1.0:
    print "1°"
elif angle % int(angle) < 0.5:
    print str(int(angle)) + "°"
else:
    print str(int(angle) + 1) + "°"
