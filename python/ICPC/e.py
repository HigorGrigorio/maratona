def preenche(remain, tiles, R, E):
    menor = remain
    maior = max(R, E)
    for i in range(maior, 0, -1):
        if tiles[i]:
            tiles[i] = False
            if i <= R:
                menor = min(menor, preenche(remain-i, tiles, R-i, E))
            if i <= E:
                menor = min(menor, preenche(remain-i, tiles, R, E-i))
            tiles[i] = True
    return menor

I = [int(x) for x in input().split(" ")]
N = I[0]
K = I[1]
E = I[2]
R = N - K - E
tiles = [True] * (N+1)

tiles[0] = False
remain = N - K
tiles[K] = False

if tiles[E]:
    tiles[E] = False
    remain -= E
    E = 0
if tiles[R]:
    tiles[R] = False
    remain -= R
    R = 0

print(preenche(remain, tiles, R, E))