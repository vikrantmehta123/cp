import sys
from collections import Counter

data = list(map(int, sys.stdin.read().split()))
n, m = data[:2]
ticket_prices = data[2:2+n] # size n
maximum_prices = data[2+n:2+n+m] # size m

D = Counter(ticket_prices)

ticket_prices = sorted(D.keys())

def binary_search(arr, target):
    left, right = 0, len(arr)
    while left < right:
        mid = (left + right) // 2
        if arr[mid] <= target:
            left = mid + 1
        else:
            right = mid
    return left - 1

for price in maximum_prices:
    if  len(ticket_prices) == 0 or price < ticket_prices[0]:
        print(-1)
    else:
        idx = binary_search(ticket_prices, price)
        closest_price = ticket_prices[idx]
        print(closest_price)
        ticket_prices.pop(idx)
