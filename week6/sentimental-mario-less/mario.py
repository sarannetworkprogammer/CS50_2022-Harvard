# TODO
from cs50 import get_int
# conditon for checking inputs
while True:

    Height = get_int("Height: ")

    if Height > 0 and Height < 9:
        break
# printing the values

for i in range(0, Height):
    print((Height-i-1)*" ", end="")
    print("#"*(i+1))
