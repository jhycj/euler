N = input() 

N = int(N) 

answer = 0 
for i in range(N): 
    answer += (i+1) * (N-i)

print(answer)