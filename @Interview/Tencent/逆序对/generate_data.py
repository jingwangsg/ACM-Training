import numpy as np

n = np.random.randint(15, 20)
size = 2 ** n
m = 20
data = np.random.randint(10000000, size=size)
query = np.random.randint(1, n, size=m)
print(n)
print(data)
print(m)
print(query)

with open("./in.txt", "w") as f:
    f.write(str(n))
    f.write("\n")
    for item in data:
        f.write(str(item))
        f.write(" ")
    f.write("\n")
    f.write(str(m))
    f.write("\n")
    for item in query:
        f.write(str(item))
        f.write(" ")
