N = input()
 
N = int(N)

even_sum = 0 
odd_sum = 0 

for i in range (N) : 
    if((i+1) %2 ==0): 
        even_sum += (i+1)

    else: 
        odd_sum += (i+1) 

print(even_sum)
print(odd_sum)
