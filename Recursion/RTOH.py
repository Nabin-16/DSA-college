move=0
def TOH(n, src, dst, temp):
    global move
    if n == 1:
        print(f"Move disc {n} from {src} to {dst}")
        move += 1
    else:
        TOH(n-1, src, temp, dst)
        print(f"Move disc {n} from {src} to {dst}")
        move += 1
        TOH(n-1, temp, dst, src)
n = int(input("Enter the number of discs: "))
TOH(n, '1', '3', '2')
print(f"Total moves: {move}")
