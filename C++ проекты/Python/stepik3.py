byk = 10
kor = 5
tel = 0.5
count = 0
for i in range(1, 10):
    for j in range(1, 10):
        for k in range(1, 100): 
            if i * byk + j * kor + k * tel == 100:
                count = i + j + k
                if count == 100:
                    print("бык =", i, "корова =", j, "теленок =", k)