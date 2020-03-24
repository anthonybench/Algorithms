# The sum of the squares of the first ten natural numbers is: 1*2 + 2*2 + ... + 10*2 = 385
# The square of the sum of the first ten natural numbers is: (1 + 2 + ... + 10)*2 = 55*2 = 3025
# Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

# Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.


sumOfSquares = 0
sumOfNums = 0
squareOfSum = 0
for i in range(1,101):
    sumOfSquares += i**2
    sumOfNums += i
    if i == 100:
        squareOfSum = sumOfNums**2


print("THE SUM OF THE SQUARES IS " + str(sumOfSquares))
print("THE SQUARE OF THE SUM IS " + str(squareOfSum))
print("HENCE THE DIFFERENCE IS " + str(squareOfSum - sumOfSquares))