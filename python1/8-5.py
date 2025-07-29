def isPrime(num):
    if n>2:
        for i in range(2,n,1):
            if n%i==0:
                return 0
        else:
            return 1
    elif n==2:
        return 1
    else:
        return 0

def reverseNumber(num):
    num=str(n)
    numR=num[::-1]
    if num==numR:
        return n
    else:
        return -1

N = int(input())
for n in range(1,N+1):
    if isPrime(n) and reverseNumber(n) == n:
        print(n)