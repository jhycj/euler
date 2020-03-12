N = input() 
N = int(N) 

answer = 0 

for i in range(N): 
    answer += (i+1) * (i+1) 

print(answer)