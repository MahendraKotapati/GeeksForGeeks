n = int(input())
l1 = list(input().split())
l2 = list(input().split())
l3 = list(input().split())
s = ""
i = 0
while(i < n):
  if(l1[i] == "#" and l2[i] == "#" and l3[i]=="#"):
    s = s + "#"
    i =  i + 1
    continue
  if(i+2 > n - 1):
    i = i + 1
    continue
  if(l1[i] == "." and l1[i+1] == "*" and l1[i+2] == "."):
    if(l2[i] == "" and l2[i+1] == "" and l2[i+2] == "*"):
      if(l3[i] == "" and l3[i+1] == "." and l3[i+2] == ""):
        s = s + "A"
        i = i + 3
        continue
  if(l1[i] == "" and l1[i+1] == "" and l1[i+2] == "*"):
    if(l2[i] == "" and l2[i+1] == "" and l2[i+2] == "*"):
      if(l3[i] == "" and l3[i+1] == "" and l3[i+2] == "*"):
        s = s + "E"
        i = i + 3
        continue
  if(l1[i] == "" and l1[i+1] == "" and l1[i+2] == "*"):
    if(l2[i] == "." and l2[i+1] == "*" and l2[i+2] == "."):
      if(l3[i] == "" and l3[i+1] == "" and l3[i+2] == "*"):
        s = s + "I"
        i = i + 3
        continue
          
  if(l1[i] == "" and l1[i+1] == "" and l1[i+2] == "*"):
    if(l2[i] == "" and l2[i+1] == "." and l2[i+2] == ""):
      if(l3[i] == "" and l3[i+1] == "" and l3[i+2] == "*"):
        s = s + "O"
        i = i + 3
        continue
  if(l1[i] == "" and l1[i+1] == "." and l1[i+2] == ""):
    if(l2[i] == "" and l2[i+1] == "." and l2[i+2] == ""):
      if(l3[i] == "" and l3[i+1] == "" and l3[i+2] == "*"):
        s = s + "U"
        i = i + 3
        continue
  i = i + 1
print(s)