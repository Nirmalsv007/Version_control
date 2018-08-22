cachememory=[]
#LOADS INITIAL CACHE
def loadcache(cachesize):
	loadfile=open("test.txt","r");
	n=0
	for each in loadfile:
		if n<cachesize:
			cachememory.insert(n,each)
			n=n+1
		else:
			break

#READ THE ADRESS FROM THE FILE
def getadress(n):
	readfile=open("test.txt","r")
	m=0
	for each in readfile:
		if m==n:
			return each
		else:
			m=m+1
#HIT OR MISS CALCULATION
def check(adress,n,cachesize):
	if adress in cachememory:
		return 1
	else:	
		cachememory.pop(0)
		m=0
		cachememory.insert(cachesize-1,getadress(cachesize+m))
		m=m+1
		return 0

file=open("test.txt","r")
cachesize=int(input("Enter the cache size"))
n=0
CacheHit=0
CacheMiss=0
for line in file:
	if n==0:
		CacheMiss=CacheMiss+1
		loadcache(cachesize)
		n=n+1
	else:
		if(check(line,n,cachesize)==1):
			CacheHit=CacheHit+1
		else:
			CacheMiss=CacheMiss+1
print("Cache Hit is",CacheHit)
print("Cache Miss is",CacheMiss)
