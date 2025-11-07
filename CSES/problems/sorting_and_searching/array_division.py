import sys

data = list(map(int, sys.stdin.read().split()))

n = data[0]
k = data[1]
arr = data[2:]

total = sum(arr)
avg = total // k

# ----------------------------------------------------------
# Feasibility test: can we partition into <= k parts
# such that each part has sum <= mid?
# (MUST use <= k to maintain monotonicity)
# ----------------------------------------------------------
def can_partition(arr, n, k, mid):
    curr_sum = 0
    parts_used = 1

    for x in arr:
        if x > mid:   # impossible case
            return False

        if curr_sum + x <= mid:
            curr_sum += x
        else:
            parts_used += 1
            curr_sum = x
            if parts_used > k:
                return False

    return True


# ----------------------------------------------------------
# 1. Binary search for minimal possible max subarray sum
# ----------------------------------------------------------
low = avg
high = total
ans = total

while low <= high:
    mid = (low + high) // 2

    if can_partition(arr, n, k, mid):
        ans = mid
        high = mid - 1
    else:
        low = mid + 1

# ----------------------------------------------------------
# Output as your original code: print only the minimal max sum
# ----------------------------------------------------------
print(ans)
