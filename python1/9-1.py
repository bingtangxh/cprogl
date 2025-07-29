# -*- coding: UTF-8 -*-


import math
x1,y1=map(int, raw_input().split(','))
r=float(raw_input())
x2,y2=map(int, raw_input().split(','))

delta=(x1-x2) ** 2 + (y1-y2) ** 2

if delta<=r*r:
    print "( %d, %d )在圆内" %(x2,y2)
else:
    print "( %d, %d )在圆外" %(x2,y2)