def twoSum(arr: list[int], target: int) -> list[int]:
    left: int = 0
    right: int = (len(arr)) - 1

    while left < right:
        if arr[left] + arr[right] == target:
            return [left+1, right+1]
        elif arr[left] + arr[right] < target:
            left += 1
        else: right -= 1
    return [-1, -1]

def validPalindrome(s: str) -> bool:
    left: int = 0
    right: int = (len(s)) - 1

    while left < right:
        while left < right and not s[left].isalnum():
            left += 1
        while left < right and not s[right].isalnum():
            right -= 1
        if s[left].lower() != s[right].lower():
            return False

        left += 1;
        right -= 1;

    return True

def threeSum(arr: list[int]) -> list[list[int]]:
    ans: list[list[int]] = []
    sorted_arr = sorted(arr)
    n = len(sorted_arr)
    for i in range(n-2):
        if i > 0 and sorted_arr[i] == sorted_arr[i - 1]:
            continue

        left = i + 1
        right = n - 1
        while left < right:
            sum = sorted_arr[i] + sorted_arr[left] + sorted_arr[right]
            if sum == 0:
                ans.append([sorted_arr[i], sorted_arr[left], sorted_arr[right]])
                left += 1
                right -= 1
            elif sum < 0:
                left += 1
            else: right -= 1

    return ans

def containerWMostWater(arr: list[int]) -> int:
    left = 0
    right = len(arr) - 1
    maxArea = 0

    while left < right:
        area = (right - left) * min(arr[left], arr[right])
        maxArea = max(maxArea, area)
        if arr[left] <= arr[right]:
            left += 1
        else: right -= 1

    return maxArea

def validTriangle(arr: list[int]) -> int:
    sorted_arr = sorted(arr)
    n = len(sorted_arr)
    count = 0
    for k in range(2, n):
        left = 0
        right = k - 1
        while left < right:
            if sorted_arr[left] + sorted_arr[right] > sorted_arr[k]:
                count += right - left
                right -= 1
            else: left += 1
    return count

def moveZeroes(arr: list[int]) -> None:
    slow = 0
    for fast in range(0, len(arr)):
        if arr[fast] != 0:
            arr[slow], arr[fast] = arr[fast], arr[slow]
            slow += 1

def sortColor(arr: list[int]) -> None:
    low = 0
    mid = 0
    high = len(arr) - 1
    while mid <= high:
        if arr[mid] == 0:
            arr[mid], arr[low] = arr[low], arr[mid]
            mid += 1
            low += 1
        elif arr[mid] == 1:
            mid += 1
        else:
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1

def trapRainWater(arr: list[int]) -> int:
    left = 0
    right = len(arr) - 1
    maxR = 0
    maxL = 0
    total = 0
    while left < right:
        if arr[left] < arr[right]:
            if arr[left] >= maxL: maxL = arr[left]
            else: total += maxL - arr[left]
            left += 1
        else:
            if arr[right] >= maxR: maxR = arr[right]
            else: total += maxR - arr[right]
            right -= 1

    return total

def main():
    # TwoSum
    arr1 = [2, 3, 5, 6, 10]
    print(twoSum(arr1, 5))

    #palindrome
    s = "A man, a plan, a canal: Panama"
    print(validPalindrome(s))

    #3sum
    arr2 = [-1,0,1,2,-1,-4]
    print(threeSum(arr2))

    #container
    arr3 = [1,8,6,2,5,4,8,3,7]
    print(containerWMostWater(arr3))

    #triangle
    arr4 = [2,2,3,4]
    print(validTriangle(arr4))

    #moveZeroes
    arr5 = [0,1,0,3,12]
    moveZeroes(arr5)
    print(arr5)

    #sortColor
    arr6 = [2,0,2,1,1,0]
    sortColor(arr6)
    print(arr6)

    #trapWater
    arr7 = [0,1,0,2,1,0,1,3,2,1,2,1]
    print(trapRainWater(arr7))

main()