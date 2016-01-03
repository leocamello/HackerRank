M, T, X = float(input()), int(input()), int(input())

tip = (T * M) / 100
tax = (X * M) / 100

final_price = round(M + tip + tax, 0)

print("The final price of the meal is $" + str(int(final_price)) + ".")
