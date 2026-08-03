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

def main():
    # TwoSum
    arr1 = [2, 3, 5, 6, 10]
    print(twoSum(arr1, 5))

    #palindrome
    s = "A man, a plan, a canal: Panama"
    print(validPalindrome(s))

main()