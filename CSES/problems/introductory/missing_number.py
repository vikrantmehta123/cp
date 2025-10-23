import sys

data = list(map(int, sys.stdin.read().split()))

n = data[0]
arr = data[1:]

present = [False] * (n + 1)

for i in range(len(arr)):
    num = arr[i]
    present[num] = True

answer = 0
for i in range(1, n + 1):
    if not present[i]:
        answer = i
        break
print(answer)