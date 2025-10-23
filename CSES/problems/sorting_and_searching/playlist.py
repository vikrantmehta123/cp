import sys

data = list(map(int, sys.stdin.read().split()))

n = data[0]
arr = data[1:]

idx = {}
count = 0 
maxcount = 0
start, end = 0, 0
for i, num in enumerate(arr):
    if num not in idx or idx[num] < start:
        end = i
        idx[num] = i
    else:
        last_idx = idx[num]
        end = i 
        start = last_idx + 1
        idx[num] = i

    count = end + 1 - start

    if count > maxcount:
        maxcount = count

sys.stdout.write(str(maxcount))
