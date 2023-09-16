import math

def trapezoidal_rule(f, a, b, n):
    """
    f: функция, которую необходимо проинтегрировать
    a, b: пределы интегрирования
    n: количество трапеций
    """
    h = (b - a) / n
    s = 0.5 * (f(a) + f(b))

    for i in range(1, n):
        s += f(a + i * h)

    return s * h

def f(x):
    return (math.cos(0.4*x+0.6)) / (0.8 + math.sin(pow(x,2) + 0.6))

integral = trapezoidal_rule(f, 0.4, 1.2, 8)
print(integral)