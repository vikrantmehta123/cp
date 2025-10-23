import sys

data = list(map(int, sys.stdin.read().split()))

n, x = data[0:2]
arr = data[2:]

arr = [(val, i+1) for i, val in enumerate(arr)]  # 1-based index
arr.sort()

l, r = 0, n - 1
while l < r:
    s = arr[l][0] + arr[r][0]
    if s == x:
        print(arr[l][1], arr[r][1])
        break
    elif s < x:
        l += 1
    else:
        r -= 1
else:
    print("IMPOSSIBLE")