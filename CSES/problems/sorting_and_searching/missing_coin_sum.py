import sys

data = list(map(int, sys.stdin.read().split()))

n = data[0]
arr = data[1:]

arr.sort()

candidate = 0 #  We can make all numbers between [1, candidate]
found = False
for i, num in enumerate(arr):
    if num > candidate + 1:
        found = True
        print(candidate + 1)
        break
    else:
        candidate += num

if not found:
    print(candidate + 1)