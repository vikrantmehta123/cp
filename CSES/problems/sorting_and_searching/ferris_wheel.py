import sys

data = list(map(int, sys.stdin.read().split()))
n, max_weight = data[:2]
weights = data[2:2+n]
weights.sort() 

count = 0

i = 0
j = n - 1

while i <= j:
    if weights[i] + weights[j] <= max_weight:
        count += 1
        i += 1
        j -= 1
    else:
        count += 1
        j -= 1

print(count)