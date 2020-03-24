#==============================
# Main Program
# TEST.py
#==============================

# module imports
import time
import random
from tools import space
from tools import border
from binarySearch import binary_search
from linearSearch import linear_search

# parameters
##
MAX = 40000
##
random.seed()
test = [i for i in range(1, MAX+1)]
target = random.randint(1, MAX)

# print opening
space(3)
border('D')
print("Target:", target)
print("Input Size:", MAX)

# LINEAR SEARCH TEST
start = time.time()
res = linear_search(test, target)
end = time.time()
border('S')
space(1)
print("Linear Search Timer: ", end-start, "s", sep='')
print("Index Returned: ", res, sep='')
space(1)
border('M')

# BINARY SEARCH TEST
start = time.time()
res = binary_search(test, target)
end = time.time()
border('M')
space(1)
print("Binary Search Timer: ", end-start, "s", sep='')
print("Index Returned: ", res, sep='')
space(1)

# print closing
border('D')
space(3)

