import sys

data = list(map(int, sys.stdin.read().split()))
n = data[0]

times = [(data[i], data[i+1]) for i in range(1, 2*n+1, 2)]

times.sort(key=lambda x:x[1])

count = 1

prev_end = None
for i in range(1, n):
    if prev_end is None:
        prev_end = times[i-1][1]

    curr_start = times[i][0]
    curr_end = times[i][1]

    if curr_start >= prev_end:
        count += 1
        prev_end = curr_end
print(count)