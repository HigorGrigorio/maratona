C = input()

T = []
P = []

while True:
    p = input()

    if p == '0':
        break

    l, c = int(p[0]), p[1]
    # verificar cantos

    if l != 1:
        # checar direita
        if c == 'a':
            T.append(str(l - 1) + 'b')
            continue
        # checar esquerda
        if c == 'h':
            T.append(str(l - 1) + 'g')
            continue

        T.append(str(l - 1) + chr(ord(c) + 1))
        T.append(str(l - 1) + chr(ord(c) - 1))

l, c = int(C[0]), C[1]


def moviments(pos):
    chars = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
    l, c = int(pos[0]), chars.index(pos[1])
    res = []

    moviments = [(l-2, c-1), (l-2, c+1), (l-1, c-2),
                 (l-1, c+2), (l+1, c-2), (l+1, c+2), (l+2, c-1), (l+2, c+1)]

    for moviment in moviments:
        if moviment[0] >= 1 and moviment[0] <= 8 and moviment[1] >= 0 and moviment[1] <= 7:
            res.append(str(moviment[0]) + chars[moviment[1]])

    return res


print(moves(C))
