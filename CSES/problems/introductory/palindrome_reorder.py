import sys
from collections import Counter


def solve(s):
    D = Counter(s)

    start = [ ]

    odd_char = ''
    for k, v in D.items():
        if v % 2 == 0:
            start.append( k * (v // 2) )
        else:
            if odd_char == '':
                odd_char = k * v
            else:
                return ('NO SOLUTION')
        
    end = reversed(start)
    end = "".join(end)
    start = "".join(start)

    return start + odd_char + end
    
s = sys.stdin.read().strip()

ans = solve(s)
print(ans)