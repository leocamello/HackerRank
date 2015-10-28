englishCount = int(raw_input())
englishSubscribers = set(map(int, raw_input().split()))

frenchCount = int(raw_input())
frenchSubscribers = set(map(int, raw_input().split()))

print len(englishSubscribers.difference(frenchSubscribers))
