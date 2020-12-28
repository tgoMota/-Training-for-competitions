import math
def dist(x1,y1, x2, y2):
    return math.sqrt((x1-x2)**2 + (y1-y2)**2)
a1, b1 = input().split(' ')
a2, b2 = input().split(' ')
a1 = float(a1)
b1 = float(b1)
a2 = float(a2)
b2 = float(b2)
print(round(dist(a1,b1,a2,b2),4))
