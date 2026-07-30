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

arr = [1, 2, 3, 4, 5]

print(linear_search(arr, 3))
print(binary_search(arr, 3))
