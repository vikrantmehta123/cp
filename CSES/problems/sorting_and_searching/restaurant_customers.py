import sys
import heapq


# Approach 1: Using MinHeap
data = list(map(int, sys.stdin.read().split()))
n = data[0]

times = [(data[i], data[i+1]) for i in range(1, 2*n+1, 2)]
def restaurant_customers(times):
    times.sort(key=lambda x: x[0])
    heap = []  
    max_count = 0

    for start, end in times:
        while heap and heap[0] <= start:
            heapq.heappop(heap)
        heapq.heappush(heap, end)
        max_count = max(max_count, len(heap))

    return max_count

print(restaurant_customers(times))

# Approach 2: Using Two Pointers
# data = list(map(int, sys.stdin.read().split()))
# n = data[0]
# arrivals = []
# departures = []
# for i in range(1, 2*n+1, 2):
#     arrivals.append( data[i] )
#     departures.append(data[i+1] )
# arrivals.sort()
# departures.sort()

# i, j = 0, 0
# maxcount = 0 
# count = 0

# while i < n and j < n:
#     if arrivals[i] < departures[j]:
#         count += 1
#         maxcount = max(maxcount, count)
#         i += 1
#     else:
#         count -= 1
#         j += 1

# print(maxcount)