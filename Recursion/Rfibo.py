max = 100
table = [-1] * max
# def initialize():
#     global table
#     for i in range(max):
#         table[i] = -1
def fibom(n):
    global table
    if (n==1 or n==2):
        return 1
    if table[n] != -1:
        return table[n]
    table[n] = fibom(n - 1) + fibom(n - 2)
    return table[n]
n= int(input("Enter a number: "))
if (n <0 or n >= max):
    print(f'Please enter a number between 0 and {max-1}.')
# initialize()
print(f'Fibonacci of {n} is {fibom(n)}')