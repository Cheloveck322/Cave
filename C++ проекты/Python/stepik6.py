sum_del = 0
max_chislo = 0
a = int(input())
b = int(input())

for i in range(a, b + 1):
    count = 0
    sum = 0
    for j in range(1, i + 1):
        if (i % j == 0):
            count = i
            sum += j
    if count > max_chislo:
        max_chislo = count
    if sum > sum_del:
        sum_del = sum

print(max_chislo, sum_del)