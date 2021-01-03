def fat(n):
    if n<=1: return 1
    return n*fat(n-1)

def comb(n,k):
    return fat(n)/(fat(n-k)*fat(k))

t = int(input())
for ti in range(1,t+1):
    n, k, p = input().split(" ")
    n = int(n)
    k = int(k)
    p = float(p)/100
    cp = 1-p
    ans = (cp**(n-k)*p**k*comb(n,k))*100
    print(f"A chance de Basy acertar o numero no dia {ti} eh %.2f" % ans + "%")
