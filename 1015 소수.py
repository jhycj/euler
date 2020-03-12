a = input() 
b = input() 

a = int(a)
b = int(b) 


def make_prime_list(uppbd): 

    if(uppbd == 1) :
        ret = []  
        return ret 
    elif(uppbd == 2) : 
        ret = [2] 
        return ret 
    else: 
        prime_list = [2]

        for n in range(3, uppbd+1) : 
            count= 0 

            for p in prime_list: 
                if(n % p != 0) :    
                    count += 1  
            
            if(count == len(prime_list)): 
                prime_list.append(n)

        return prime_list 


prime_list = make_prime_list(b)
#print(prime_list)

pp = [] 

for p in prime_list : 
    if p >= a: 
        pp.append(p)

if(len(pp) ==0 ): 
    print(-1) 

else : 
    pp.sort()
    print(sum(pp)) 
    print(pp[0])
