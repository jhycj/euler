a, b, c = input().split() 
a= int(a)
b= int(b)
c = int(c)

def add(a,b,c):
    if(a+b==c): 
        print("%d+%d=%d" %(a,b,c)) 
        return 0 
    if(a==b+c): 
        print("%d=%d+%d" %(a,b,c)) 
        return 0
    else: 
        return 1 

def subtract(a, b,c): 
    if(a-b==c): 
        print("%d-%d=%d" %(a,b,c)) 
        return 0 
    if(a==b-c): 
        print("%d=%d-%d" %(a,b,c)) 
        return 0
    else: 
        return 1

def multiply(a, b,c): 
    if(a*b==c): 
        print("%d*%d=%d" %(a,b,c)) 
        return 0 
    if(a==b*c): 
        print("%d=%d*%d" %(a,b,c)) 
        return 0
    else: 
        return 1 

def divide(a, b,c): 
    if(a/b==c): 
        print("%d/%d=%d" %(a,b,c)) 
        return 0 
    if(a==b/c): 
        print("%d=%d/%d" %(a,b,c)) 
        return 0
    else: 
        return 1 

a = int(a)
b= int(b)
c = int(c)
ret=add(a,b,c)
if(ret!=0): 
    ret = subtract(a,b,c) 
    if(ret!=0):
        ret = multiply(a,b,c) 
        if(ret!=0): 
            ret= divide(a,b,c) 

