T = int(raw_input())

for i in range(0, T):
    n = int(raw_input())
    sideLengths = map(int, raw_input().split())

    left, right = 0, n - 1

    top = -1
    failed = False
    while right - left > 0 and failed == False:
        if sideLengths[left] > sideLengths[right]:
            if top >= sideLengths[left] or top == -1:
                top = sideLengths[left]
                left += 1
            else:
                failed = True
        else:
            if top >= sideLengths[right] or top == -1:
                top = sideLengths[right]
                right -= 1
            else:
                failed = True

    if failed:
        print "No"
    else:
        print "Yes"
