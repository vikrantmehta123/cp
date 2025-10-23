import sys

data = list(map(int, sys.stdin.read().split()))

n = data[0]
arr = data[1:]
arr.sort()

count = 1

for i in range(1, n):
    if arr[i - 1] != arr[i]:
        count += 1

print(count)