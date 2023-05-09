def calc(total, queue, sum, res, i=0):
    if len(queue) == i:
        if sum == total:
            print(sum)
            res.append(res)
        return
    val = queue[i]
    calc(total, queue, sum + val, res, i + 1)
    calc(total, queue, sum - val, res, i + 1)


N, F = [int(x) for x in input().split()]
queue = []

for i in range(N):
    queue.append(int(input()))

print(queue)
print(calc(F, queue, 0, []))
