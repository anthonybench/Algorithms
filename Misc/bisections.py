# Problem 7 functions

def EtoN(e):
	evens = [i for i in range(2, e+1) if i%2==0]
	naturals = [i for i in range(1, len(evens)+1)]
	for i in range(len(evens)):
		if evens[i] == e:
			return naturals[i]

def NtoZ(n):
	negZ = [-i for i in range(1, n+1)]
	posZ = [i for i in range(0, n+1)]
	evens = [i for i in range(1, 2*n + 1) if i%2==0]
	odds = [i for i in range(1, 2*n + 1) if i%2!=0]
	for i in range(0, n+1):
		if evens[i] == n:
			return posZ[i]
		elif odds[i] == n:
			return negZ[i]

def NtoQplus(n):
	primes = []
	for i in range(1,n):
		if n%i == 0:
			flag = True
			for i in range(10):
	return ((-1)**n)*((n+1)//2)

def ZtoQ(z):
	if z < 0:
		return ((z-1)/z)
	elif z == 0:
		return 0
	else:
		return ((z+1)/z)

def EtoQ(e):
	if e % 4 == 0:
		return (e)
	else:
		return (e/(e+1))

test = [1,2,3,4,5,6,7,8,9,10]
for i in test:
	print(NtoZ(i))
