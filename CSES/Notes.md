# How to accept inputs

## All Lines

```python3

import sys

data = sys.stdin.read().split()  # Data is the list of lines from text file  
```

## Single Number

```python3
n = int(data[0])
```

## Array of Numbers

```python3
arr = list(map(int, data))  # converts all tokens to integers
```
