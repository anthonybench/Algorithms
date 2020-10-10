'''
Binary Search

Runtime Complexity within O(Log2(n))

takes a sorted (smallest to largest) list of integers and integer to find, returns index of target or -1 if not found
'''

def binary_search(array: list, target: int) -> int:
    low = 0
    high = len(array)
    mid = (high + low) // 2
    while low < high:
        mid = (high + low) // 2
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            low = mid + 1
        elif array[mid] > target:
            high = mid
    return -1

