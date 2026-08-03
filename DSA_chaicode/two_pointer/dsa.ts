function twoSum(arr: number[], target: number): number[] {

    let left: number = 0;
    let right: number = arr.length - 1

    while(left < right){
        let sum = arr[left] + arr[right];
        if(sum === target) return [left + 1, right + 1];
        else if(sum < target) left++;
        else right--;
    }
    return [-1, -1]
}

function validPalindrome(s: string): boolean{
    const cleaned = s.replace(/[^a-zA-Z0-9]/g, "").toLowerCase();
    let left = 0;
    let right = cleaned.length - 1;
    while(left < right){
        if(cleaned[left] !== cleaned[right]) return false;
        left++;
        right--;
    }
    return true;
}

function main(){
    // TwoSum
    const arr1 = [2, 3, 5, 6, 10];
    console.log(twoSum(arr1, 5))

    //palindrome
    const s = "A man, a plan, a canal: Panama"
    console.log(validPalindrome(s))
}

main()