N = input() 

N = int(N) 
answer = 1 
for i in range(N):  
    answer *= (i+1) 
print(answer)