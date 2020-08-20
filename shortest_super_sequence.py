t=int(input())

for _ in range(t):

    str1,str2=input().split()
    len1=len(str1)
    len2=len(str2)

    dp = [ [0]*(len2+1) for _ in range(len1+1) ]

    for i in range(1,len1+1):
        for j in range(1,len2+1):

            if(str1[i-1]==str2[j-1]):
                dp[i][j]=dp[i-1][j-1]+1
            else:
                dp[i][j]=max(dp[i][j-1],dp[i-1][j])
    
    print(len1+len2-dp[len1][len2])