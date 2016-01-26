D, M, Y = 0, 1, 2

actual = list(map(int, input().split()))
expected = list(map(int, input().split()))

fine = 0
if actual[Y] - expected[Y] > 0:
    fine = 10000
elif actual[Y] - expected[Y] == 0:
    if actual[M] - expected[M] > 0:
        fine = 500 * (actual[M] - expected[M])
    elif actual[M] - expected[M] == 0:
        if actual[D] - expected[D] > 0:
            fine = 15 * (actual[D] - expected[D])

print(fine)
        
