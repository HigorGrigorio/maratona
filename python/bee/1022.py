def mdc(a, b):
    if b == 0:
        return a
    else:
        return mdc(b, a % b)

def main(): 
    n = int(input())

    while n > 0:
        arr = input().split()

        a, b, c, d = int(arr[0]), int(arr[2]), int(arr[4]), int(arr[6])
        op = arr[3]


        if op == '*':
            x = a * c
            y = b * d
        elif op == '+':
            x = a * d + b * c
            y = b * d
        elif op == '-':
            x = a * d - b * c
            y = b * d
        elif op == '/':
            x = a * d
            y = b * c

        m = mdc(x, y);

        print('{}/{} = {}/{}'.format(x, y, x // m, y // m))
        n-=1;
        
main()