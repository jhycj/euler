N = input() 
N = int(N) 

answer = 1 
for i in range(N): 
    answer *= (i+1) 

s = ''
for i in range(N-1): 
    s += str(i+1)+'*'

s += str(N)

print("%d!=(%s)=%d" %(N, s, answer))