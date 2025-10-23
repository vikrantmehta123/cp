import sys

data = list(map(int, sys.stdin.buffer.read().split()))
n, m = data[0], data[1]
arr = data[2:2 + n]
ops = data[2 + n:]
operations = [(ops[i], ops[i + 1]) for i in range(0, len(ops), 2)]

pos = [0] * (n + 1)
for i, val in enumerate(arr):
    pos[val] = i

# compute initial round count
count = 1
for i in range(2, n + 1):
    if pos[i - 1] > pos[i]:
        count += 1

out = [""] * m
for i, (a, b) in enumerate(operations):
    if a == b:
        out[i]= (str(count))
        continue

    a -= 1
    b -= 1
    va = arr[a]
    vb = arr[b]

    # collect affected values, deduplicated manually for speed
    affected = []
    for v in (va, va + 1, vb, vb + 1):
        if 1 <= v <= n and v not in affected:
            affected.append(v)

    # subtract old contributions
    for v in affected:
        if v > 1 and pos[v - 1] > pos[v]:
            count -= 1

    # swap in both arr and pos
    arr[a], arr[b] = arr[b], arr[a]
    pos[va], pos[vb] = pos[vb], pos[va]

    # add new contributions
    for v in affected:
        if v > 1 and pos[v - 1] > pos[v]:
            count += 1


    out[i]= (str(count))

sys.stdout.write("\n".join(out))
