def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return True
    return False 

def binary_search(arr, target):
    low = 0
    high = (len(arr)) - 1

    while(low < high):
        mid = low + (high - low) // 2
        val = arr[mid]
        if(val == target):
            return True
        elif(val > target):
            high = mid - 1
        else:
            low = mid + 1
    return False

def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(len(arr) - 1 - i):
            if(arr[j] > arr[j+1]):
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr
    

arr = [1, 2, 3, 4, 5]
arr1 = [5, 3, 8, 1, 2]

print(linear_search(arr, 3))
print(binary_search(arr, 3))
print(bubble_sort(arr1))
