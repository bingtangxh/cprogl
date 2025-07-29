import re

str=input()
result=re.split(r'[\[\],]',str)
result1=[str1 for str1 in result if str1]
result2=[int(x) for x in result1]
addObj=int(input())
result2.append(addObj)
result2.sort(reverse=False)
print(result2)
