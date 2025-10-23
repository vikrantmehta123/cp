import sys

data = list(map(int, sys.stdin.read().split()))
n, m, k = data[:3]
desired_apartment_sizes = data[3:3+n]
actual_apartment_sizes = data[3+n:3+n+m]

desired_apartment_sizes.sort() # size n
actual_apartment_sizes.sort() # size m

i, j = 0, 0

count = 0
while i < n and j < m:
    diff = abs(desired_apartment_sizes[i] - actual_apartment_sizes[j])
    if diff <= k:
        count += 1
        i += 1
        j += 1
    else:
        if actual_apartment_sizes[j] < desired_apartment_sizes[i]:
            j += 1
        else:
            i += 1

print(count)
