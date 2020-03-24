# A palindromic number reads the same both ways.
# The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

# Find the largest palindrome made from the product of two 3-digit numbers.


# Make a list of all the palindromes made by multiplying 2 3-digit numbers...

palindromes = []
for i in range(100,999):
    for n in range(100,999):
        if str(i*n)[0] == str(i*n)[-1] and str(i*n)[1] == str(i*n)[-2] and str(i*n)[2] == str(i*n)[-3]:
            palindromes.append(i*n)

 # Pick the largest value from the list!

print(max(palindromes))

