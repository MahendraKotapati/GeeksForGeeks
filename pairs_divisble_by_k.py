import math

t=int(input())

for _ in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    mp={}
    len1=len(arr)
    k=4

    for i in range(k):
        mp[i]=0

    for i in range(len1):
        mp[arr[i]%k]+=1

    c=0
    for i in range(len1):
        r=k-arr[i]%k
        
        if(r==4): r=0
        if r in mp.keys():
            c+=mp[r]
            if(r==k/2 or r==0 ):
                c-=1
    
    print(c//2)
             
                




        
    