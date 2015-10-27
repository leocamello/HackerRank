n = int(raw_input())

heights = set(map(float, raw_input().split()))

print sum(heights) / len(heights)
