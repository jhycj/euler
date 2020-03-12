N = input()
N = int(N) 

answer = 0 
for i in range(100): 
    answer += N*(i+1) 

print(answer)