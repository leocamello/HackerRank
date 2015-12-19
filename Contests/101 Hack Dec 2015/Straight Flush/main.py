import re

ranks, suits = [], []

rank_characters = "A23456789TJQKA"
rank_dict = {"A": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9, "T": 10, "J": 11, "Q": 12, "K": 13}

for _ in range(5):
    card = str(input().strip())
    suits.append(card[1])
    ranks.append(card[0])

suit_cond = all(suit == suits[0] for suit in suits)

rank_cond = False
ranks = sorted(ranks, key=lambda x: rank_dict[x])
if ranks[0] == "A" and (ranks[4] == "5" or ranks[4] == "K"):
    rank_cond = re.search(("").join(ranks[1:5]), rank_characters)
else:
    rank_cond = re.search(("").join(ranks), rank_characters)

if  suit_cond and rank_cond:
    print("YES")
else:
    print("NO")
