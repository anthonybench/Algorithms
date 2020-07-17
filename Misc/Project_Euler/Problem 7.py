# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
# What is the 10001st prime number?


# Generate a list of prime numbers....
n = 2
lastPrime = 15
primes = []

while len(primes) < lastPrime:
    if n > 1:

        for i in range(2,n):
            if (n % i) == 0:
                break
        else:
            primes.append(n)

    n += 1


# Pick the last one determined by 'lastPrime'!
print(primes)
print("THE NUMBER OF PRIMES GENERATED IS: " + str(len(primes)))
print("THE LARGEST PRIME OF THE LIST IS: " + str(primes[-1]))