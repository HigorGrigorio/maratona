
while True:
    n = int(input())

    if(n == 0): 
        break;

    while n > 0:
        n = n - 1

        arr =  [int(x) for x in input().split()]
        black = None

        for i in range(len(arr)): 
            if(arr[i] <= 127):
                if(black == None):
                    black = i
                else:
                    black = None
                    break

        if(black == None):
            print('*')
        else:
            out = ['A', 'B', 'C', 'D', 'E']
            print(out[black])
            
        
        
