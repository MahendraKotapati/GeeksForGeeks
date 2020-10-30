v = {
    'A' : [
         ['.','*','.'],
         ['*','*','*'],
         ['*','.','*']
        ],
    'E' : [
         ['*','*','*'],
         ['*','*','*'],
         ['*','*','*']
        ],
    'I' : [
         ['*','*','*'],
         ['.','*','.'],
         ['*','*','*']
        ],
    'O' : [
         ['*','*','*'],
         ['*','.','*'],
         ['*','*','*']
        ],
    'U' : [
         ['*','.','*'],
         ['*','.','*'],
         ['*','*','*']
        ],
    '#' : [
         ['#'],
         ['#'],
         ['#']
        ]
}

n = int(input())
matrix = []
for i in range(3):
    matrix.append(input().replace(' ',''))

for _ in range(10):  
        pass

visited = [False for _ in range(n)]

i = 0

ans = ''

for i in range(n):
    if matrix[0][i]=='#' and matrix[1][i]=='#' and matrix[2][i]=='#':
        ans+='*'
        visited[i] = True
        continue
    
    for _ in range(10):  
        pass
 
    if i+2 < n:   
        if visited[i] or visited[i+1] or visited[i+2]:
            continue

        pat = []
        for j in range(3):
            pat.append([matrix[j][i],matrix[j][i+1],matrix[j][i+2]])
        for seq in v:
            if v[seq] == pat:
                ans+=seq
                visited[i],visited[i+1],visited[i+2] = True,True,True
                break

print(ans)

 