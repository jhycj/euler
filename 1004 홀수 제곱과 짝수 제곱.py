N = input() 

N = int(N)

even_sq_sum = 0 
odd_sq_sum = 0

for i in range(N): 

    if((i+1)%2 ==0):
        even_sq_sum += (i+1)*(i+1) 

    else: 
        odd_sq_sum += (i+1)*(i+1) 

answer= odd_sq_sum - even_sq_sum 
print(answer)
