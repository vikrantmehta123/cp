import sys

data = list(map(int, sys.stdin.read().split()))

n = data[0]
arr = data[1:]

maxsum = arr[0]
sum_ = arr[0]
for i in range(1, len(arr)):


    # The core idea is from dynamic programming:
    # Whether to extend the subarray or start a new one
    # sum_ => represents the max subarray sum for a subarray ending at ith index
    # Here's how we can represent the recurrence:
    # best[i]=max(arr[i],arr[i]+best[i−1])

    # Case 1: sum_ > 0 & arr[i] > 0 => extend as extending increases the sum
    # Case 2: sum_ > 0 & arr[i] < 0 => extend as positive num + negative number >= negative number
    # Case 3: sum_ < 0 & arr[i] > 0 => start new 
    # Case 4: sum_ < 0 & arr[i] < 0 => start a new subarray, as starting fresh gives higher sum

    # The following condition concisely achieves the above four cases
    # sum_ = max(arr[i], arr[i] + sum_) 

    if sum_ >= 0 and arr[i] >= 0: sum_ += arr[i]
    elif sum_ >= 0 and arr[i] < 0: sum_ += arr[i]
    elif sum_ < 0 and arr[i] >= 0: sum_ = arr[i]
    else: sum_ = arr[i]

    # Keeping track of global maximum
    maxsum = max(sum_, maxsum)


print(maxsum)