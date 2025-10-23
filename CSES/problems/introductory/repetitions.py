import sys

data = sys.stdin.read().strip()  # reads entire input and removes leading/trailing whitespace

max_len = 1
curr_char = data[0]
curr_len = 1
for char in data[1:]:
    if char == curr_char:
        curr_len += 1 
        if curr_len > max_len:
            max_len = curr_len

    else:
        curr_len = 1
        curr_char = char

print(max_len)