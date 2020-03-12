N = input() 
N = int(N) 
answer = 0 
for i in range(N-1) : 
    if(i+1) %3 ==0 : 
        answer+= (i+1) 
        #print(i+1)
    
    if(i+1) % 5 ==0 : 
        answer+= (i+1) 
        #print(i+1)

    if(i+1) % 15 ==0 : 
        answer -= (i+1) 
        #print(i+1)
print(answer)