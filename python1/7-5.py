raw_str=input()
list=raw_str.split(',')
setA={1, 2, 3, 4, 5}
setB={6, 7, 8, 9, 10}
dictA={}
dictB={}
for i in list:
    j=int(i)
    if j in setA:
        dictA[j]=dictA.get(j, 0) + 1
    elif j in setB:
        dictB[j]=dictB.get(j, 0) + 1

flag=False
for i in sorted(setA):
    if i not in dictA:
        if flag==True:
            print(' ', end='')
        print(i, end='')
        flag=True
print('')
flag=False
for i in sorted(setB):
    if i not in dictB:
        if flag==True:
            print(' ', end='')
        print(i, end='')
        flag=True
