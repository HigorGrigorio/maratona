N = int(input())

while (N != 0):
    word = input()
    if len(word) == 3:
        if word[0] == 't' or word[2] == 'o':
          print(2)
        else:
          print(1)
    else:
      print(3)
    N = N - 1;