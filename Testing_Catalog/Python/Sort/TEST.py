#==============================
# Main Program
# TEST.py
#==============================

# module imports
import time
import random
from tools import space
from tools import border
from selectionSort import selection_sort
from mergeSort import merge_sort
from quickSort import quick_sort

# parameters
##
MAX = 20
##
random.seed()
test1 = [random.randint(1, MAX) for i in range(MAX)]
test2 = test1
test3 = test1

# print opening
space(3)
border('D')
print("Input Size:", MAX)
print("Input:", test1)

# SELECTION SORT TEST
start = time.time()
selection_sort(test1)
end = time.time()
border('S')
space(1)
print("Selection Sort Timer: ", end-start, "s", sep='')
print("List Returned:", test1)
space(1)
border('M')

# MERGE SORT TEST
start = time.time()
merge_sort(test2)
end = time.time()
border('M')
space(1)
print("Merge Sort Timer: ", end-start, "s", sep='')
print("List Returned:", test2)
space(1)
border('M')

# QUICK SORT TEST
start = time.time()
quick_sort(test3, 0, MAX - 1)
end = time.time()
border('M')
space(1)
print("Quick Sort Timer: ", end-start, "s", sep='')
print("List Returned:", test3)
space(1)

# print closing
border('D')
space(3)

