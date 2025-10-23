import sys

data = list(map(int, sys.stdin.read().split()))

n = data[0]
arr = data[1:]

ans = 0
for i in range(1, n):
    if arr[i - 1] > arr[i]:
        ans += arr[i - 1] - arr[i]
        arr[i] = arr[i - 1]

print(ans)