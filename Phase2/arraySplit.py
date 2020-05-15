t1, t2 = input().split()
n, k = int(t1), int(t2)

l=[]

stringList = input().split()

for i in stringList:
	l.append(int(i))


l.reverse() 
suff = [sum(l[ : i + 1 ]) for i in range(len(l))]
suff.reverse()


suff2 = [suff[0]]
suff.pop(0)
suff.sort(reverse=True)

for i in suff:
	suff2.append(i)

ans = 0

for i in range(k):
	ans += suff2[i]

print(ans)