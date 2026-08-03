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

function threeSum(arr: number[]): number[][]{
    let sorted = arr.sort((a, b) => a - b)
    let ans: number[][] = [];
    const n = sorted.length
    for(let i = 0; i < n - 2; i++){
        if(i > 0 && sorted[i] === sorted[i-1]) continue;
        let left = i + 1;
        let right = n - 1;
        while(left < right){
            let sum = sorted[i] + sorted[left] + sorted[right]
            if(sum == 0){
                ans.push([arr[i], arr[left], arr[right]])
                left++;
                right--;
            }else if(sum < 0) left++;
            else right--;
        }
    }
    return ans;
}

function main(){
    // TwoSum
    const arr1 = [2, 3, 5, 6, 10];
    console.log(twoSum(arr1, 5))

    //palindrome
    const s = "A man, a plan, a canal: Panama"
    console.log(validPalindrome(s))

    //3sum
    const arr2 = [-1,0,1,2,-1,-4];
    console.log(threeSum(arr2))
}

main()