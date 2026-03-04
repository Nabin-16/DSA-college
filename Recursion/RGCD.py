def iGCD(a,b):
    if b==0:
        return a
    else:
        return iGCD(b, a % b)
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
print(f"GCD of {a} and {b} is {iGCD(a, b)}")