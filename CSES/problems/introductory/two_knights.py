n = int(input())

for i in range(1, n+1):
    if i == 1:
        print(0)
    elif i == 2:
        print(6)
    else:
        total_pairs = ((i ** 2) * ((i ** 2) - 1) // 2 )
        ans = total_pairs - 4*(i - 1)*(i - 2)
        print(ans)  