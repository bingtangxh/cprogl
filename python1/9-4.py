def maxd(a,b):
    r=1
    for i in range(2,min(a,b)+1):
        while a%i==0 and b%i==0:
            r*=i
            a//=i
            b//=i
    return r

def minr(a,b):
    r=1
    for i in range(2,min(a,b)+1):
        while a%i==0 and b%i==0:
            r*=i
            a//=i
            b//=i
    return r*a*b


a,b=input().split(',')
a,b=eval(a),eval(b)
isLessthan0=0
if(a<0):
    a=0-a
    isLessthan0+=1
if(b<0):
    b=0-b
    isLessthan0+=1
if(isLessthan0==1):
    isLessthan0=-1
else:
    isLessthan0=1
print("%d,%d"%(isLessthan0*maxd(a,b),minr(a,b)))