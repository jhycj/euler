n = input()
n = int(n)


for i in range(9): 
    answer = n*(i+1)
    print('%d*%d=%d' %(n, i+1, answer))