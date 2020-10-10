'''
Quick Sort: Python

Runtime Complexity within O(n*Log2(n))

Takes array, returns sorted array
'''

def swap(array: list, i: int, j: int):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp
    return

def partition(array: list, low: int, high: int) -> int:
    i = low
    j = high

    while i < j:
        while (i < high) and (array[i] <= array[low]):
            i += 1
        while array[j] > array[low]:
            j -= 1
        if i < j:
            swap(array, i, j)
    swap(array, low, j)

    return j

def quick_sort(array: list, low: int, high: int):
    if low >= high:
        return

    pivot = partition(array, low, high)

    quick_sort(array, low, pivot - 1)
    quick_sort(array, pivot + 1, high)

    return

