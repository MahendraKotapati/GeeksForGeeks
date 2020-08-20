t=int(input())

for _ in range(t):
    n=int(input())
    mp=list(input().split())  
    str = input()
    len1=len(str)

    dp = [ [False]*(len1+1) for _ in range(len1+1) ] 

    for i in range(len1+1):
        dp[i][0] = True 

    for i in range(1,len1+1):
        for j in range(1,len1+1):
            if(str[i-1:j] in mp):
                dp[i][j] = dp[i][i-1]|dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j]
    

    '''for i in range(0,len1+1):
        for j in range(0,len1+1):
            print(dp[i][j],end=' ')
        print("\n")
    '''
    if(dp[len1][len1]):
        print("1") 
    else: 
        print("0")



