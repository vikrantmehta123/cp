t = int(input())

for _ in range(t):
    row, col = map(int, input().split())
    max_ = max(row, col)
    
    start = ( max_ - 1 ) ** 2  + 1
    end = max_ ** 2

    reverse = (max_ % 2 == 0)

    if reverse:
        range_ = [end, start]
    else:
        range_ = [start, end]

    if row >= col:
        idx = col - 1
    
    else:
        idx = col - 1
        idx += col - row

    if reverse:
        print(range_[0] - idx)
    else:
        print(range_[0] + idx)
