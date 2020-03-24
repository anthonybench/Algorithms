'''
Linear Search

Runtime Complexity within O(n)

takes list of integers and integer to find, returns index of target or -1 if not found
'''

def linear_search(array: list, target: int) -> int:

    for i in range(len(array)):
        if array[i] == target:
            return i;
    return -1

