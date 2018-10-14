#!/usr/bin/python3
def fac(n):
    ans = 1
    for i in range(1, n + 1):
        ans *= i
    return ans
def C(m, n):
    return fac(n) / fac(m) / fac(n - m)

print((C(500, 1500) - 500 * C(499, 1000)))
