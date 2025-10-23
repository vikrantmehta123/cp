t = int(input())

for _ in range(t):
    a, b = map(int, input().split())

    x = (2*b - a)
    y = (2*a - b)

    if x >=0 and y >= 0 and (x + y ) % 3 == 0 :
        print("YES")

    else:
        print("NO")