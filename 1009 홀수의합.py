a = input() 
b = input() 

a = int(a) 
b = int(b) 

answer = 0 
for i in range(a, b+1): 
    if(i%2 ==1): 
        answer += i 

print(answer)