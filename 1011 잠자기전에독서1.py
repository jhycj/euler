N = input()
N = int(N) 

answer = 0 
for i in range(N) : 
    if N % (i+1) ==0: 
        answer += i+1 

print(answer)