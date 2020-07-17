# A Pythagorean triplet is a set of three natural numbers, a < b < c, for which: a**2 + b**2 = c**2

# For example, 3**2 + 4**2 = 9 + 16 = 25 = 5**2.

# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.


# Couple for-loops and a conditional should slay the dragon...

for i in range(1,1000):
    for x in range(1,1000):
        if i + x + (i**2 + x**2)**(1/2) == 1000:
            print(i*x*(1000-i-x))