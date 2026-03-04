def fibo(n):
    if n == 1 or n == 2:
        return 1
    else:
        return fibo(n - 1) + fibo(n - 2)

n = int(input("Enter a number: "))
if n < 1:
    print("Please enter a number greater than 1.")
else:
    print(f"Fibonacci of {n} is {fibo(n)}")
