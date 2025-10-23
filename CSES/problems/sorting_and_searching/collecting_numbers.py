import sys

data = list(map(int, sys.stdin.read().split()))

n = data[0]
arr = data[1:]

seen = set()

count = 0
for i in range(n):
    num = arr[i]
    if len(seen) == 0:
        count += 1
        seen.add(num)
    else:
        if num - 1 in seen:
            seen.add(num)
        else:
            count += 1
            seen.add(num)


print(count)
