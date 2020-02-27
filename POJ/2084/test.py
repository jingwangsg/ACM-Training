import numpy as np

f = np.zeros(210);
f[1] = 1
f[0] = 1

def calc_f(n):
    if (f[n]): return f[n]
    ret = 0
    for i in range(2, 2*n+1, 2):
        ret += calc_f((i-2)//2) * calc_f((2*n - i)//2)
    f[n] = ret
    return ret

print(str(calc_f(100)))