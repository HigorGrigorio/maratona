while True:
    B, N = [int(x) for x in input().split()]

    if not B or not N:
        break

    bank = [int(x) for x in input().split()]

    for i in range(N):
        D, C, V = [int(x) for x in input().split()]

        bank[D - 1] = bank[D - 1] - V
        bank[C - 1] = bank[C - 1] + V

    flag = False

    for v in bank:
        if v < 0:
            flag = True
            break
    
    if not flag:
        print('S')
    else: 
        print('N')







