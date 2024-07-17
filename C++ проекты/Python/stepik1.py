import math

num = int(input())

count = 1
for i in range(1, num + 1):
    for j in range(count):
        print('*', end='')
    if i < math.ceil(num / 2):
        count += 1
    else:
        count -= 1
    print()