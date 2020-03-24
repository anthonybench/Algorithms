# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
# Find the sum of all the primes below two million.


# Primes are hard....recycle code from problem 7...

n = 2
limit = 1000
primes = []
prime = 0
primeSum = 0

while prime <= limit:

    for i in range(2,n):
        if (n % i) == 0:
            break
    else:
        primes.append(n)
        prime = n
        primeSum += n

    n += 1



print("THE LAST PRIME ADDED WAS: " + str(prime))
print("SO I'LL JUST GO AHEAD AND SUBTRACT THE LAST ENTRY...")
print("THE SUM OF THE PRIMES IS: " + str(primeSum - primes[-1]))
