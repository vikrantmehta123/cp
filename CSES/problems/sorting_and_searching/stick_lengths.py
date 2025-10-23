import sys

data = list(map(int, sys.stdin.read().split()))

n = data[0]
arr = data[1:]

arr.sort()

mid = (n) // 2
median = arr[mid]

min_cost = 0
for num in arr:
    min_cost += abs(median - num)

print(min_cost)