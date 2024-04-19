import math

from random import randint
result = math.e != math.pow(2, 4)
print(int(result))

for i in range(10):
    print(randint(1,2), end='')
print("")    

for i in range(5):
    print(" ")
    for k in range(i+1):
        print("*", end=" ")
